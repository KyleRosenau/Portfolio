extends CharacterBody2D

const SPEED = 90.0
const JUMP_VELOCITY = -200.0

@onready var animated_sprite = $AnimatedSprite2D
@onready var animation_player: AnimationPlayer = $AnimationPlayer
@onready var isDead = false

#check if spacebar is pushed
func _input(ev):
	if Input.is_key_pressed(KEY_SPACE):
		animation_player.play("Jump")

#check if not standing on something
func _physics_process(delta: float) -> void:
	# Add the gravity.
	if not is_on_floor():
		velocity += get_gravity() * delta

	# Handle jump.
	if Input.is_action_just_pressed("jump") and is_on_floor():
		velocity.y = JUMP_VELOCITY

	#get input direction: -1, 0, 1
	var direction := Input.get_axis("move_left", "move_right")
	
	#check if dead
	#if get_node("CollisionShape2D") == null:
	#print(get_node("isDead"))
	if get_node("isDead") == null:
		isDead = true;
	
	#flip sprite
	if direction > 0:
		animated_sprite.flip_h = false
	elif direction < 0:
		animated_sprite.flip_h = true
		
	#play animations
	if is_on_floor():
		if direction == 0:
			animated_sprite.play("idle")
		if isDead == true:
			animated_sprite.play("dead")
		else:
			animated_sprite.play("run")
	else:
		if isDead == true:
			animated_sprite.play("dead")
		else:
			animated_sprite.play("jump")

	#apply movement
	if direction:
		velocity.x = direction * SPEED
	else:
		velocity.x = move_toward(velocity.x, 0, SPEED)

	move_and_slide()
