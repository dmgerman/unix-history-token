begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: object.h,v 7.0.1.2 86/12/12 17:01:38 lwall Exp $ */
end_comment

begin_comment
comment|/* $Log:	object.h,v $  * Revision 7.0.1.2  86/12/12  17:01:38  lwall  * Baseline for net release.  *   * Revision 7.0.1.1  86/10/16  10:52:30  lwall  * Added Damage.  Fixed random bugs.  *   * Revision 7.0  86/10/08  15:13:04  lwall  * Split into separate files.  Added amoebas and pirates.  *   */
end_comment

begin_define
define|#
directive|define
name|Root
value|0
end_define

begin_define
define|#
directive|define
name|Base
value|1
end_define

begin_define
define|#
directive|define
name|Enterprise
value|2
end_define

begin_define
define|#
directive|define
name|Star
value|3
end_define

begin_define
define|#
directive|define
name|Torp
value|4
end_define

begin_define
define|#
directive|define
name|Enemy
value|5
end_define

begin_define
define|#
directive|define
name|Web
value|6
end_define

begin_define
define|#
directive|define
name|Crusher
value|7
end_define

begin_typedef
typedef|typedef
struct|struct
name|object
block|{
name|char
name|posx
decl_stmt|,
name|posy
decl_stmt|;
ifdef|#
directive|ifdef
name|SIGNEDCHAR
name|char
name|velx
decl_stmt|,
name|vely
decl_stmt|;
else|#
directive|else
name|short
name|velx
decl_stmt|,
name|vely
decl_stmt|;
endif|#
directive|endif
name|struct
name|object
modifier|*
name|next
decl_stmt|,
modifier|*
name|prev
decl_stmt|,
modifier|*
name|contend
decl_stmt|;
name|long
name|energy
decl_stmt|;
name|long
name|mass
decl_stmt|;
name|char
name|type
decl_stmt|;
name|char
name|image
decl_stmt|;
name|char
name|strategy
decl_stmt|;
name|char
name|flags
decl_stmt|;
block|}
name|OBJECT
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PIRATE
value|1
end_define

begin_comment
comment|/* we may mutiny */
end_comment

begin_define
define|#
directive|define
name|FRIENDLY
value|2
end_define

begin_comment
comment|/* we aren't really an enemy, for now */
end_comment

begin_define
define|#
directive|define
name|STATIC
value|4
end_define

begin_comment
comment|/* we are not in the movers list at the moment */
end_comment

begin_define
define|#
directive|define
name|COUNTDOWN
value|8
end_define

begin_comment
comment|/* we are counting down for something */
end_comment

begin_define
define|#
directive|define
name|CLOAKS
value|16
end_define

begin_comment
comment|/* we can cloak */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DOINIT
end_ifdef

begin_decl_stmt
name|OBJECT
name|root
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
operator|&
name|root
block|,
operator|&
name|root
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|Root
block|,
literal|'?'
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|EXT
name|OBJECT
name|root
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DOINIT
end_ifdef

begin_decl_stmt
name|OBJECT
name|free_root
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
operator|&
name|free_root
block|,
operator|&
name|free_root
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
name|Root
block|,
literal|'?'
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|EXT
name|OBJECT
name|free_root
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|EXT
name|OBJECT
modifier|*
name|ent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|OBJECT
modifier|*
name|base
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|OBJECT
modifier|*
name|enemies
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|OBJECT
modifier|*
name|movers
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|OBJECT
modifier|*
name|realapollo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|OBJECT
modifier|*
name|nuke
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|OBJECT
modifier|*
name|occupant
index|[
name|YSIZE
index|]
index|[
name|XSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|OBJECT
modifier|*
name|make_object
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unmake_object
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_object
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|object_init
parameter_list|()
function_decl|;
end_function_decl

end_unit

