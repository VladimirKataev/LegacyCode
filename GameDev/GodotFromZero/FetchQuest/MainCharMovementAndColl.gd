extends KinematicBody2D

# class member variables go here, for example:
# var a = 2
# var b = "textvar"
var xPos = 0
var yPos = 0
var xSpeed = 0;
var ySpeed = 0;
func _ready():
	# Called every time the node is added to the scene.
	# Initialization here
	set_fixed_process(true)


func _fixed_process(delta):
	ySpeed = 0
	xSpeed = 0
	if(Input.is_action_pressed("CharDown")):
		ySpeed = 100
	if(Input.is_action_pressed("CharUp")):
		ySpeed = -100
	if(Input.is_action_pressed("CharLeft")):
		xSpeed = -100
	if(Input.is_action_pressed("CharRight")):
		xSpeed =  100
	var motion = Vector2(xSpeed, ySpeed)
	move(motion*delta)
