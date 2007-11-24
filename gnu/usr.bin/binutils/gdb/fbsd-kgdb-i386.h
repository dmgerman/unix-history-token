begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FBSD_KGDB_I386_H
end_ifndef

begin_define
define|#
directive|define
name|FBSD_KGDB_I386_H
end_define

begin_include
include|#
directive|include
file|"i386/tm-fbsd.h"
end_include

begin_include
include|#
directive|include
file|"fbsd-kgdb.h"
end_include

begin_comment
comment|/* Override FRAME_SAVED_PC to enable the recognition of signal handlers.  */
end_comment

begin_undef
undef|#
directive|undef
name|FRAME_SAVED_PC
end_undef

begin_define
define|#
directive|define
name|FRAME_SAVED_PC
parameter_list|(
name|FRAME
parameter_list|)
define|\
value|(kernel_debugging \     ? fbsd_kern_frame_saved_pc (FRAME) \     : i386bsd_frame_saved_pc (FRAME))
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|fbsd_kern_frame_saved_pc
parameter_list|(
name|struct
name|frame_info
modifier|*
name|fr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Offset to saved PC in sigcontext, from<sys/signal.h>.  */
end_comment

begin_comment
comment|/* DEO:XXX where is this really from??? */
end_comment

begin_define
define|#
directive|define
name|SIGCONTEXT_PC_OFFSET
value|20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FBSD_KGDB_I386_H */
end_comment

end_unit

