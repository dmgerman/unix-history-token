begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|TESTFLOAT_SPARC64_MILIEU_H_
end_ifndef

begin_define
define|#
directive|define
name|TESTFLOAT_SPARC64_MILIEU_H_
end_define

begin_comment
comment|/* ===============================================================================  This C header file is part of TestFloat, Release 2a, a package of programs for testing the correctness of floating-point arithmetic complying to the IEC/IEEE Standard for Floating-Point.  Written by John R. Hauser.  More information is available through the Web page `http://HTTP.CS.Berkeley.EDU/~jhauser/arithmetic/TestFloat.html'.  THIS SOFTWARE IS DISTRIBUTED AS IS, FOR FREE.  Although reasonable effort has been made to avoid it, THIS SOFTWARE MAY CONTAIN FAULTS THAT WILL AT TIMES RESULT IN INCORRECT BEHAVIOR.  USE OF THIS SOFTWARE IS RESTRICTED TO PERSONS AND ORGANIZATIONS WHO CAN AND WILL TAKE FULL RESPONSIBILITY FOR ANY AND ALL LOSSES, COSTS, OR OTHER PROBLEMS ARISING FROM ITS USE.  Derivative works are acceptable, even for commercial purposes, so long as (1) they include prominent notice that the work is derivative, and (2) they include prominent notice akin to these four paragraphs for those parts of this code that are retained.  =============================================================================== */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------------- Include common integer types and flags. ------------------------------------------------------------------------------- */
end_comment

begin_include
include|#
directive|include
file|"sparc64.h"
end_include

begin_comment
comment|/* ------------------------------------------------------------------------------- If the `BITS64' macro is defined by the processor header file but the version of SoftFloat being used/tested is the 32-bit one (`bits32'), the `BITS64' macro must be undefined here. ------------------------------------------------------------------------------- #undef BITS64 */
end_comment

begin_comment
comment|/* ------------------------------------------------------------------------------- Symbolic Boolean literals. ------------------------------------------------------------------------------- */
end_comment

begin_enum
enum|enum
block|{
name|FALSE
init|=
literal|0
block|,
name|TRUE
init|=
literal|1
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

end_unit

