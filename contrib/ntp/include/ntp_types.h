begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  ntp_types.h - defines how int32 and u_int32 are treated.  *  For 64 bit systems like the DEC Alpha, they have to be defined  *  as int and u_int.  *  For 32 bit systems, define them as long and u_long  */
end_comment

begin_include
include|#
directive|include
file|"ntp_machine.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_NTP_TYPES_
end_ifndef

begin_define
define|#
directive|define
name|_NTP_TYPES_
end_define

begin_comment
comment|/*  * This is another naming conflict.  * On NetBSD for MAC the macro "mac" is defined as 1  * this is fun for us as a packet structure contains an  * optional "mac" member - severe confusion results 8-)  * As we hopefully do not have to rely on that macro we  * just undefine that.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|mac
end_ifdef

begin_undef
undef|#
directive|undef
name|mac
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Set up for prototyping  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|P
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_PROTOTYPES
argument_list|)
end_if

begin_define
define|#
directive|define
name|P
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __STDC__ and not HAVE_PROTOTYPES */
end_comment

begin_define
define|#
directive|define
name|P
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __STDC__ and HAVE_PROTOTYPES */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* P */
end_comment

begin_comment
comment|/*  * VMS DECC (v4.1), {u_char,u_short,u_long} are only in SOCKET.H,  *			and u_int isn't defined anywhere  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VMS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<socket.h>
end_include

begin_typedef
typedef|typedef
name|unsigned
name|int
name|u_int
typedef|;
end_typedef

begin_comment
comment|/*  * Note: VMS DECC has  long == int  (even on __alpha),  *	 so the distinction below doesn't matter  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

begin_if
if|#
directive|if
operator|(
name|SIZEOF_INT
operator|==
literal|4
operator|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|int32
end_ifndef

begin_define
define|#
directive|define
name|int32
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|u_int32
end_ifndef

begin_define
define|#
directive|define
name|u_int32
value|unsigned int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not sizeof(int) == 4 */
end_comment

begin_if
if|#
directive|if
operator|(
name|SIZEOF_LONG
operator|==
literal|4
operator|)
end_if

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not sizeof(long) == 4 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|int32
end_ifndef

begin_define
define|#
directive|define
name|int32
value|long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|u_int32
end_ifndef

begin_define
define|#
directive|define
name|u_int32
value|unsigned long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not sizeof(long) == 4 */
end_comment

begin_include
include|#
directive|include
file|"Bletch: what's 32 bits on this machine?"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not sizeof(int) == 4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NTP_TYPES_ */
end_comment

end_unit

