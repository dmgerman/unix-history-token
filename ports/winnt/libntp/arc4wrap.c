begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * arc4wrap.c - wrapper for libevent's ARCFOUR random number generator  *  * Written by Juergen Perlinger (perlinger@ntp.org) for the NTP project.  * The contents of 'html/copyright.html' apply.  * --------------------------------------------------------------------  * This is an inclusion wrapper for the ARCFOUR implementation in  * libevent. It's main usage is to enable a openSSL-free build on Win32  * without a full integration of libevent. This provides Win32 specific  * glue to make the PRNG working. Porting to POSIX should be easy, but  * on most POSIX systems using openSSL is no problem and falling back to  * using ARCFOUR instead of the openSSL PRNG is not necessary. And even  * if it is, there's a good chance that ARCFOUR is a system library.  */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_include
include|#
directive|include
file|<wincrypt.h>
end_include

begin_include
include|#
directive|include
file|<process.h>
end_include

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|this is currently a pure windows port
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"ntp_types.h"
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_comment
comment|/* ARCFOUR implementation glue */
end_comment

begin_comment
comment|/* export type is empty, since this goes into a static library*/
end_comment

begin_define
define|#
directive|define
name|ARC4RANDOM_EXPORT
end_define

begin_comment
comment|/* we use default uint32_t as UINT32 */
end_comment

begin_define
define|#
directive|define
name|ARC4RANDOM_UINT32
value|uint32_t
end_define

begin_comment
comment|/* do not use ARCFOUR's default includes - we gobble it all up here. */
end_comment

begin_define
define|#
directive|define
name|ARC4RANDOM_NO_INCLUDES
end_define

begin_comment
comment|/* And the locking. Could probably be left empty. */
end_comment

begin_define
define|#
directive|define
name|ARC4_LOCK_
parameter_list|()
value|private_lock_()
end_define

begin_define
define|#
directive|define
name|ARC4_UNLOCK_
parameter_list|()
value|private_unlock_()
end_define

begin_comment
comment|/* support code */
end_comment

begin_function
specifier|static
name|void
name|evutil_memclear_
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
block|{
name|memset
argument_list|(
name|buf
argument_list|,
literal|0
argument_list|,
name|len
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* locking uses a manual thread-safe ONCE pattern. There's no static  * initialiser pattern that can be used for critical sections, and  * we must make sure we do the creation exactly once on the first call.  */
end_comment

begin_decl_stmt
specifier|static
name|long
name|once_
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|CRITICAL_SECTION
name|csec_
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|private_lock_
parameter_list|(
name|void
parameter_list|)
block|{
name|again
label|:
switch|switch
condition|(
name|InterlockedCompareExchange
argument_list|(
operator|&
name|once_
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
condition|)
block|{
case|case
literal|0
case|:
name|InitializeCriticalSection
argument_list|(
operator|&
name|csec_
argument_list|)
expr_stmt|;
name|InterlockedExchange
argument_list|(
operator|&
name|once_
argument_list|,
literal|2
argument_list|)
expr_stmt|;
case|case
literal|2
case|:
name|EnterCriticalSection
argument_list|(
operator|&
name|csec_
argument_list|)
expr_stmt|;
break|break;
default|default:
name|YieldProcessor
argument_list|()
expr_stmt|;
goto|goto
name|again
goto|;
block|}
block|}
end_function

begin_function
specifier|static
name|void
name|private_unlock_
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|InterlockedExchangeAdd
argument_list|(
operator|&
name|once_
argument_list|,
literal|0
argument_list|)
operator|==
literal|2
condition|)
name|LeaveCriticalSection
argument_list|(
operator|&
name|csec_
argument_list|)
expr_stmt|;
block|}
end_function

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4244
name|)
end_pragma

begin_include
include|#
directive|include
file|"../../../sntp/libevent/arc4random.c"
end_include

end_unit

