extends Area2D

@onready var timer = $Timer
@onready var animation_player: AnimationPlayer = $AnimationPlayer
#@onready var isDead = false

func _on_body_entered(body):
	animation_player.play("Hurt")
	Engine.time_scale = .5
	#isDead = true
	#body.get_node("CollisionShape2D").queue_free()
	body.get_node("isDead").queue_free()
	timer.start()


func _on_timer_timeout() -> void:
	Engine.time_scale = 1
	get_tree().reload_current_scene()
