begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id$ */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/tty.h>
end_include

begin_include
include|#
directive|include
file|<i386/include/pc/display.h>
end_include

begin_include
include|#
directive|include
file|<i386/include/console.h>
end_include

begin_include
include|#
directive|include
file|<i386/include/apm_bios.h>
end_include

begin_include
include|#
directive|include
file|<i386/i386/cons.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/isa.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/isa_device.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/syscons.h>
end_include

begin_decl_stmt
specifier|extern
name|scr_stat
modifier|*
name|cur_console
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_short
modifier|*
name|Crtat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|crtc_addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|scr_map
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|scrn_blanked
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|palette
index|[]
decl_stmt|;
end_decl_stmt

end_unit

