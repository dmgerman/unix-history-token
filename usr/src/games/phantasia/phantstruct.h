begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * phantstruct.h - structure definitions for Phantasia  */
end_comment

begin_struct
struct|struct
name|player
comment|/* player statistics */
block|{
name|double
name|p_experience
decl_stmt|;
comment|/* experience */
name|double
name|p_level
decl_stmt|;
comment|/* level */
name|double
name|p_strength
decl_stmt|;
comment|/* strength */
name|double
name|p_sword
decl_stmt|;
comment|/* sword */
name|double
name|p_might
decl_stmt|;
comment|/* effect strength */
name|double
name|p_energy
decl_stmt|;
comment|/* energy */
name|double
name|p_maxenergy
decl_stmt|;
comment|/* maximum energy */
name|double
name|p_shield
decl_stmt|;
comment|/* shield */
name|double
name|p_quickness
decl_stmt|;
comment|/* quickness */
name|double
name|p_quksilver
decl_stmt|;
comment|/* quicksilver */
name|double
name|p_speed
decl_stmt|;
comment|/* effective quickness */
name|double
name|p_magiclvl
decl_stmt|;
comment|/* magic level */
name|double
name|p_mana
decl_stmt|;
comment|/* mana */
name|double
name|p_brains
decl_stmt|;
comment|/* brains */
name|double
name|p_poison
decl_stmt|;
comment|/* poison */
name|double
name|p_gold
decl_stmt|;
comment|/* gold */
name|double
name|p_gems
decl_stmt|;
comment|/* gems */
name|double
name|p_sin
decl_stmt|;
comment|/* sin */
name|double
name|p_x
decl_stmt|;
comment|/* x coord */
name|double
name|p_y
decl_stmt|;
comment|/* y coord */
name|double
name|p_1scratch
decl_stmt|,
name|p_2scratch
decl_stmt|;
comment|/* variables used for decree, player battle */
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
name|bool
name|ring_inuse
decl_stmt|;
comment|/* ring in use flag */
block|}
name|p_ring
struct|;
comment|/* ring stuff */
name|long
name|p_age
decl_stmt|;
comment|/* age of player */
name|int
name|p_degenerated
decl_stmt|;
comment|/* age/3000 last degenerated */
name|short
name|p_type
decl_stmt|;
comment|/* character type */
name|short
name|p_specialtype
decl_stmt|;
comment|/* special character type */
name|short
name|p_lives
decl_stmt|;
comment|/* multiple lives for council, valar */
name|short
name|p_crowns
decl_stmt|;
comment|/* crowns */
name|short
name|p_charms
decl_stmt|;
comment|/* charms */
name|short
name|p_amulets
decl_stmt|;
comment|/* amulets */
name|short
name|p_holywater
decl_stmt|;
comment|/* holy water */
name|short
name|p_lastused
decl_stmt|;
comment|/* day of year last used */
name|short
name|p_status
decl_stmt|;
comment|/* playing, cloaked, etc. */
name|short
name|p_tampered
decl_stmt|;
comment|/* decree'd, etc. flag */
name|short
name|p_istat
decl_stmt|;
comment|/* used for inter-terminal battle */
name|bool
name|p_palantir
decl_stmt|;
comment|/* palantir */
name|bool
name|p_blessing
decl_stmt|;
comment|/* blessing */
name|bool
name|p_virgin
decl_stmt|;
comment|/* virgin */
name|bool
name|p_blindness
decl_stmt|;
comment|/* blindness */
name|char
name|p_name
index|[
name|SZ_NAME
index|]
decl_stmt|;
comment|/* name */
name|char
name|p_password
index|[
name|SZ_PASSWORD
index|]
decl_stmt|;
comment|/* password */
name|char
name|p_login
index|[
name|SZ_LOGIN
index|]
decl_stmt|;
comment|/* login */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|monster
comment|/* monster stats */
block|{
name|double
name|m_strength
decl_stmt|;
comment|/* strength */
name|double
name|m_brains
decl_stmt|;
comment|/* brains */
name|double
name|m_speed
decl_stmt|;
comment|/* speed */
name|double
name|m_energy
decl_stmt|;
comment|/* energy */
name|double
name|m_experience
decl_stmt|;
comment|/* experience */
name|double
name|m_flock
decl_stmt|;
comment|/* % chance of flocking */
name|double
name|m_o_strength
decl_stmt|;
comment|/* original strength */
name|double
name|m_o_speed
decl_stmt|;
comment|/* original speed */
name|double
name|m_maxspeed
decl_stmt|;
comment|/* maximum speed */
name|double
name|m_o_energy
decl_stmt|;
comment|/* original energy */
name|double
name|m_melee
decl_stmt|;
comment|/* melee damage */
name|double
name|m_skirmish
decl_stmt|;
comment|/* skirmish damage */
name|int
name|m_treasuretype
decl_stmt|;
comment|/* treasure type */
name|int
name|m_type
decl_stmt|;
comment|/* special type */
name|char
name|m_name
index|[
literal|26
index|]
decl_stmt|;
comment|/* name */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|energyvoid
comment|/* energy void */
block|{
name|double
name|ev_x
decl_stmt|;
comment|/* x coordinate */
name|double
name|ev_y
decl_stmt|;
comment|/* y coordinate */
name|bool
name|ev_active
decl_stmt|;
comment|/* active or not */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scoreboard
comment|/* scoreboard entry */
block|{
name|double
name|sb_level
decl_stmt|;
comment|/* level of player */
name|char
name|sb_type
index|[
literal|4
index|]
decl_stmt|;
comment|/* character type of player */
name|char
name|sb_name
index|[
name|SZ_NAME
index|]
decl_stmt|;
comment|/* name of player */
name|char
name|sb_login
index|[
name|SZ_LOGIN
index|]
decl_stmt|;
comment|/* login of player */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|charstats
comment|/* character type statistics */
block|{
name|double
name|c_maxbrains
decl_stmt|;
comment|/* max brains per level */
name|double
name|c_maxmana
decl_stmt|;
comment|/* max mana per level */
name|double
name|c_weakness
decl_stmt|;
comment|/* how strongly poison affects player */
name|double
name|c_goldtote
decl_stmt|;
comment|/* how much gold char can carry */
name|int
name|c_ringduration
decl_stmt|;
comment|/* bad ring duration */
struct|struct
block|{
name|double
name|base
decl_stmt|;
comment|/* base for roll */
name|double
name|interval
decl_stmt|;
comment|/* interval for roll */
name|double
name|increase
decl_stmt|;
comment|/* increment per level */
block|}
name|c_quickness
struct|,
comment|/* quickness */
name|c_strength
struct|,
comment|/* strength */
name|c_mana
struct|,
comment|/* mana */
name|c_energy
struct|,
comment|/* energy level */
name|c_brains
struct|,
comment|/* brains */
name|c_magiclvl
struct|;
comment|/* magic level */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|menuitem
comment|/* menu item for purchase */
block|{
name|char
modifier|*
name|item
decl_stmt|;
comment|/* menu item name */
name|double
name|cost
decl_stmt|;
comment|/* cost of item */
block|}
struct|;
end_struct

end_unit

