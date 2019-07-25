extends KinematicBody2D

# class member variables go here, for example:
# var a = 2
# var b = "textvar"
var Pos = Vector2(0,0);
func _ready():
	# Called every time the node is added to the scene.
	Pos = self.get_pos()
	set_fixed_process(true)
	pass
func _fixed_process(delta):
	if(Input.is_action_pressed("game_up")):
		Pos += Vector2(0,-10)
	if(Input.is_action_pressed("game_down")):
		Pos += Vector2(0,10)
	if(Input.is_action_pressed("game_right")):
		Pos += Vector2(10,0)
	if(Input.is_action_pressed("game_left")):
		Pos += Vector2(-10,0)
	move_to(Vector2(Pos.x, Pos.y))
	if(is_colliding()):
		print("coll")
	pass
