begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * oldplayer.h - old player structure  */
end_comment

begin_struct
struct|struct
name|oldplayer
comment|/* player statistics */
block|{
name|char
name|o_name
index|[
literal|21
index|]
decl_stmt|;
comment|/* name */
name|char
name|o_password
index|[
literal|9
index|]
decl_stmt|;
comment|/* password */
name|char
name|o_login
index|[
literal|10
index|]
decl_stmt|;
comment|/* login */
name|double
name|o_x
decl_stmt|;
comment|/* x coord */
name|double
name|o_y
decl_stmt|;
comment|/* y coord */
name|double
name|o_experience
decl_stmt|;
comment|/* experience */
name|int
name|o_level
decl_stmt|;
comment|/* level */
name|short
name|o_quickness
decl_stmt|;
comment|/* quickness */
name|double
name|o_strength
decl_stmt|;
comment|/* strength */
name|double
name|o_sin
decl_stmt|;
comment|/* sin */
name|double
name|o_mana
decl_stmt|;
comment|/* mana */
name|double
name|o_gold
decl_stmt|;
comment|/* gold */
name|double
name|o_energy
decl_stmt|;
comment|/* energy */
name|double
name|o_maxenergy
decl_stmt|;
comment|/* maximum energy */
name|double
name|o_magiclvl
decl_stmt|;
comment|/* magic level */
name|double
name|o_brains
decl_stmt|;
comment|/* brains */
name|short
name|o_crowns
decl_stmt|;
comment|/* crowns */
struct|struct
block|{
name|short
name|ring_type
decl_stmt|;
comment|/* type of ring */
name|short
name|ring_duration
decl_stmt|;
comment|/* duration of ring */
block|}
name|o_ring
struct|;
comment|/* ring stuff */
name|bool
name|o_palantir
decl_stmt|;
comment|/* palantir */
name|double
name|o_poison
decl_stmt|;
comment|/* poison */
name|short
name|o_holywater
decl_stmt|;
comment|/* holy water */
name|short
name|o_amulets
decl_stmt|;
comment|/* amulets */
name|bool
name|o_blessing
decl_stmt|;
comment|/* blessing */
name|short
name|o_charms
decl_stmt|;
comment|/* charms */
name|double
name|o_gems
decl_stmt|;
comment|/* gems */
name|short
name|o_quksilver
decl_stmt|;
comment|/* quicksilver */
name|double
name|o_sword
decl_stmt|;
comment|/* sword */
name|double
name|o_shield
decl_stmt|;
comment|/* shield */
name|short
name|o_type
decl_stmt|;
comment|/* character type */
name|bool
name|o_virgin
decl_stmt|;
comment|/* virgin */
name|short
name|o_lastused
decl_stmt|;
comment|/* day of year last used */
name|short
name|o_status
decl_stmt|;
comment|/* playing, cloaked, etc. */
name|short
name|o_tampered
decl_stmt|;
comment|/* decree'd, etc. flag */
name|double
name|o_1scratch
decl_stmt|,
name|o_2scratch
decl_stmt|;
comment|/* variables used for decree, player battle */
name|bool
name|o_blindness
decl_stmt|;
comment|/* blindness */
name|int
name|o_notused
decl_stmt|;
comment|/* not used */
name|long
name|o_age
decl_stmt|;
comment|/* age in seconds */
name|short
name|o_degenerated
decl_stmt|;
comment|/* age/2500 last degenerated */
name|short
name|o_istat
decl_stmt|;
comment|/* used for inter-terminal battle */
ifdef|#
directive|ifdef
name|PHANTPLUS
name|short
name|o_lives
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

end_unit

