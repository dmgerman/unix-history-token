begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  sol.h --  *  *	remade by A.Fujita, DEC-16-1992  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl_compat.h>
end_include

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_undef
undef|#
directive|undef
name|_POSIX_SOURCE
end_undef

begin_include
include|#
directive|include
file|<sys/signal.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|"X.h"
end_include

begin_include
include|#
directive|include
file|"Xmd.h"
end_include

begin_define
define|#
directive|define
name|NEED_EVENTS
end_define

begin_include
include|#
directive|include
file|"Xproto.h"
end_include

begin_include
include|#
directive|include
file|"osdep.h"
end_include

begin_include
include|#
directive|include
file|"misc.h"
end_include

begin_include
include|#
directive|include
file|"scrnintstr.h"
end_include

begin_include
include|#
directive|include
file|"screenint.h"
end_include

begin_include
include|#
directive|include
file|"servermd.h"
end_include

begin_include
include|#
directive|include
file|"input.h"
end_include

begin_include
include|#
directive|include
file|"inputstr.h"
end_include

begin_include
include|#
directive|include
file|"mipointer.h"
end_include

begin_include
include|#
directive|include
file|"mfb.h"
end_include

begin_comment
comment|/* dix */
end_comment

begin_function_decl
specifier|extern
name|void
name|NoopDDA
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|AddScreen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|AllocateScreenPrivateIndex
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|RegisterBlockAndWakeupHandlers
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* os */
end_comment

begin_function_decl
specifier|extern
name|int
name|AddEnabledDevice
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|RemoveEnabledDevice
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* ddx/mi */
end_comment

begin_function_decl
specifier|extern
name|Bool
name|mieqInit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mieqProcessInputEvents
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|mieqEnqueue
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|miRegisterPointerDevice
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Bool
name|miDCInitialize
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* ddx/sol */
end_comment

begin_function_decl
specifier|extern
name|void
name|solEnqueueEvents
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|solWakeupProc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* libc */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* os */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|EnabledDevices
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|LastSelectMask
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ddx/sol */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|solScreenIndex
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|monitorResolution
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lastEventTime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CARD8
modifier|*
name|solKeyModMap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|KeySymsRec
name|solKeySyms
index|[]
decl_stmt|;
end_decl_stmt

end_unit

