begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: weapon.h,v 7.0 86/10/08 15:18:20 lwall Exp $ */
end_comment

begin_comment
comment|/* $Log:	weapon.h,v $  * Revision 7.0  86/10/08  15:18:20  lwall  * Split into separate files.  Added amoebas and pirates.  *   */
end_comment

begin_decl_stmt
name|EXT
name|int
name|tractor
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|etorp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|btorp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|OBJECT
modifier|*
name|isatorp
index|[
literal|2
index|]
index|[
literal|3
index|]
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXT
name|int
name|aretorps
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|fire_torp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|attack
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fire_phaser
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tract
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|weapon_init
parameter_list|()
function_decl|;
end_function_decl

end_unit

