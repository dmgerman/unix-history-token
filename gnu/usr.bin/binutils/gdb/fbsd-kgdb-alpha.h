begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FBSD_KGDB_ALPHA_H
end_ifndef

begin_define
define|#
directive|define
name|FBSD_KGDB_ALPHA_H
end_define

begin_include
include|#
directive|include
file|"alpha/tm-fbsd.h"
end_include

begin_include
include|#
directive|include
file|"fbsd-kgdb.h"
end_include

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
value|(kernel_debugging ? fbsd_kern_frame_saved_pc(FRAME) : \ 		      alpha_saved_pc_after_call(FRAME))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FBSD_KGDB_ALPHA_H */
end_comment

end_unit

