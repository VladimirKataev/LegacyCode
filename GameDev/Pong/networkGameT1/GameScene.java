package networkGameT1;

import java.awt.Color;
import java.awt.event.KeyEvent;
import java.util.ArrayList;

import lib.*;
import json.*;

public class GameScene extends RN2Scene implements ChatClient.MessageListener {

	ChatClient chatClient;
	boolean isMaster; //Determines if this GameScene will send out oppressive data syncs
	double massDataSyncCounter = 0; //Use only if isMaster == true
	
	RN2PolygonNode paddle1, paddle2;
	RN2PolygonNode ball;
	RN2Vector ballVelocity = new RN2Vector(-20, -30);
	double ballRadius = 10;
	
	JSONObject myInfo = new JSONObject();
	public static enum PlayerNumber {
		P1, P2
	}
	public static enum Protocol {
		JOIN, MASS_DATA_SYNC, PADDLE_MOVEMENT;
	}
	// Keys to be used in data syncs
	public static enum Key {
		PROTOCOL, PLAYER_NUMBER,
		PADDLE1, PADDLE2, BALL,
		X, Y, VX, VY;
	}
	
	PlayerNumber playerNumber;
	
	
	public GameScene(RN2GamePanel gamePanel, double width, double height, PlayerNumber pNum) {
		super(gamePanel, width, height);
		this.playerNumber = pNum;
		if(pNum==PlayerNumber.P1) {
			isMaster = true;
		} else {
			isMaster = false;
		}
	}

	@Override
	public void initialize() {
		
		chatClient = new ChatClient("10.56.254.41", 6677);
		chatClient.addMessageListener(this);
		
		paddle1 = new RN2PolygonNode.
				RectBuilder().withWidth(100).withHeight(20).build();
		paddle2 = paddle1.duplicate();
		paddle2.color = Color.CYAN;
		addChild(paddle1);
		addChild(paddle2);
		
		paddle1.position.y = -230;
		paddle2.position.y = 230;
		
		ball = new RN2PolygonNode.RegularPolygonBuilder().withNumOfSides(100).withRadius(ballRadius).build();
		ball.color = Color.BLACK;
		addChild(ball);
		
	}
	
	private RN2PolygonNode getMyPaddle() {
		switch(this.playerNumber) {
		case P1:
			return paddle1;
		case P2:
			return paddle2;
		}
		return null;
	}
	
	private RN2PolygonNode getOtherPaddle() {
		switch(this.playerNumber) {
		case P1:
			return paddle2;
		case P2:
			return paddle1;
		}
		return null;
	}
	
	
	@Override
	public void update(double deltaTime) {
		RN2PolygonNode myPaddle = getMyPaddle();
		ArrayList<Integer> keysDown = gamePanel.get().keysDown;
//		if(keysDown.contains(KeyEvent.VK_UP)) {
//			myPaddle.position.y += 100*deltaTime;
//		}
//		if(keysDown.contains(KeyEvent.VK_DOWN)) {
//			myPaddle.position.y -= 100*deltaTime;
//		}
		if(keysDown.contains(KeyEvent.VK_LEFT)) {
			myPaddle.position.x -= 200*deltaTime;
		}
		if(keysDown.contains(KeyEvent.VK_RIGHT)) {
			myPaddle.position.x += 200*deltaTime;
		}
		ball.position.x += ballVelocity.dx * deltaTime;
		ball.position.y += ballVelocity.dy * deltaTime;
		if(ball.position.x - ballRadius < -this.width/2) {
			ballVelocity.dx = Math.abs(ballVelocity.dx);
		} else if(ball.position.x + ballRadius > this.width/2) {
			ballVelocity.dx = -Math.abs(ballVelocity.dx);
		}
		
		if(paddle1.containsPoint(ball.position)) {
			ballVelocity.dy = Math.abs(ballVelocity.dy);
		} else if(paddle2.containsPoint(ball.position)) {
			ballVelocity.dy = -Math.abs(ballVelocity.dy);
		}

		// Broadcast stuff
		JSONObject move = new JSONObject();
		move.put(Key.PROTOCOL.toString(), Protocol.PADDLE_MOVEMENT.toString());
		move.put(Key.PLAYER_NUMBER.toString(), playerNumber.toString());
		move.put(Key.X.toString(), myPaddle.position.x);
		move.put(Key.Y.toString(), myPaddle.position.y);
		chatClient.sendMessage(move.toString());
		
		if(isMaster) {
			massDataSyncCounter += deltaTime;
			if(massDataSyncCounter > 1) {
				massDataSyncCounter = 0;
				JSONObject sync = new JSONObject();
				sync.put(Key.PROTOCOL.toString(), 
						Protocol.MASS_DATA_SYNC.toString());
				sync.put(Key.PLAYER_NUMBER.toString(), playerNumber.toString());
				JSONObject ballCoords = new JSONObject();
				ballCoords.put(Key.X.toString(), ball.position.x);
				ballCoords.put(Key.Y.toString(), ball.position.y);
				ballCoords.put(Key.VX.toString(), ballVelocity.dx);
				ballCoords.put(Key.VY.toString(), ballVelocity.dy);

				sync.put(Key.BALL.toString(), ballCoords);
				
				chatClient.sendMessage(sync.toString());

				
			}
		}
//		myInfo.put("player", playerNumber);
//		myInfo.put("x", myPaddle.position.x);
//		myInfo.put("y", myPaddle.position.y);
//		chatClient.sendMessage(myInfo.toString());
		

	}
		
	@Override
	public void messageReceived(String msg) {
		JSONObject received = new JSONObject(msg);
		//Ignore messages from self
		if(received.get(Key.PLAYER_NUMBER.toString())
				.equals(this.playerNumber.toString())) {
			return;
		}
//		if(!received.getString("player").equals(playerNumber.toString())){
//			RN2PolygonNode otherPlayer = otherPaddle();
//			otherPlayer.position.x = received.getDouble("x");
//			otherPlayer.position.y = received.getDouble("y");
//
//		}
		if(received.getString(Key.PROTOCOL.toString())
				.equals(Protocol.PADDLE_MOVEMENT.toString())) {
			getOtherPaddle().position.x = received.getDouble(Key.X.toString());
			getOtherPaddle().position.y = received.getDouble(Key.Y.toString());

		}
		
		else if(!isMaster && received.getString(Key.PROTOCOL.toString())
				.equals(Protocol.MASS_DATA_SYNC.toString())) {
			JSONObject ballCoords = received.getJSONObject(Key.BALL.toString());
			ball.position.x = ballCoords.getDouble(Key.X.toString());
			ball.position.y = ballCoords.getDouble(Key.Y.toString());
			ballVelocity.dx = ballCoords.getDouble(Key.VX.toString());
			ballVelocity.dy = ballCoords.getDouble(Key.VY.toString());


		}
		
	}

	@Override
	public void keyDown(KeyEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void keyReleased(KeyEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseDown(RN2Click c) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseReleased(RN2Click c) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseMoved(RN2Click c) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseDragged(RN2Click c) {
		// TODO Auto-generated method stub
		
	}

}
