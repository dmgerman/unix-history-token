begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	vxdebug.h	1.2	86/01/12	*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VX_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|VXERR4
value|1
end_define

begin_define
define|#
directive|define
name|VXNOBUF
value|2
end_define

begin_decl_stmt
specifier|extern
name|long
name|vxintr4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|vxdebug
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|VXVCM
value|1
end_define

begin_define
define|#
directive|define
name|VXVCC
value|2
end_define

begin_define
define|#
directive|define
name|VXVCX
value|4
end_define

begin_include
include|#
directive|include
file|"../tahoesna/snadebug.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

