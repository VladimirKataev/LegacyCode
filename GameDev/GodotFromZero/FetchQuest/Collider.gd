extends CollisionShape2D
#extends KinematicBody2D
# class member variables go here, for example:
# var a = 2
# var b = "textvar"

func _ready():
	# Called every time the node is added to the scene.
	# Initialization here
	connect("body_enter",self,"DealCollision")
	set_fixed_process(true)
	pass