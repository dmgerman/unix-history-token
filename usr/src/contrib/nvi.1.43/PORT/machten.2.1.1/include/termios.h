begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * termios.h -- POSIX termios emulation using sgtty interface.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_termios_h_
end_ifndef

begin_define
define|#
directive|define
name|_termios_h_
end_define

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_comment
comment|/* rename to avoid name clash */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ECHO
end_ifdef

begin_define
define|#
directive|define
name|_SGTTY_ECHO
value|ECHO
end_define

begin_undef
undef|#
directive|undef
name|ECHO
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TOSTOP
end_ifdef

begin_define
define|#
directive|define
name|_SGTTY_TOSTOP
value|TOSTOP
end_define

begin_undef
undef|#
directive|undef
name|TOSTOP
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NOFLSH
end_ifdef

begin_define
define|#
directive|define
name|_SGTTY_NOFLSH
value|NOFLSH
end_define

begin_undef
undef|#
directive|undef
name|NOFLSH
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* these aren't defined in<sys/types.h> */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|speed_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|tcflag_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|cc_t
typedef|;
end_typedef

begin_comment
comment|/* control chars */
end_comment

begin_define
define|#
directive|define
name|VINTR
value|1
end_define

begin_define
define|#
directive|define
name|VQUIT
value|2
end_define

begin_define
define|#
directive|define
name|VERASE
value|3
end_define

begin_define
define|#
directive|define
name|VKILL
value|4
end_define

begin_define
define|#
directive|define
name|VEOF
value|5
end_define

begin_define
define|#
directive|define
name|VEOL
value|6
end_define

begin_define
define|#
directive|define
name|VSTART
value|7
end_define

begin_define
define|#
directive|define
name|VSTOP
value|8
end_define

begin_define
define|#
directive|define
name|VSUSP
value|9
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|VDSUSP
value|11
end_define

begin_define
define|#
directive|define
name|VREPRINT
value|12
end_define

begin_define
define|#
directive|define
name|VDISCARD
value|13
end_define

begin_define
define|#
directive|define
name|VWERASE
value|14
end_define

begin_define
define|#
directive|define
name|VLNEXT
value|15
end_define

begin_define
define|#
directive|define
name|VSTATUS
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VMIN
value|VEOF
end_define

begin_define
define|#
directive|define
name|VTIME
value|VEOL
end_define

begin_define
define|#
directive|define
name|NCCS
value|17
end_define

begin_comment
comment|/* input modes */
end_comment

begin_define
define|#
directive|define
name|IGNBRK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BRKINT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IGNPAR
value|0x00000004
end_define

begin_define
define|#
directive|define
name|PARMRK
value|0x00000008
end_define

begin_define
define|#
directive|define
name|INPCK
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ISTRIP
value|0x00000020
end_define

begin_define
define|#
directive|define
name|INLCR
value|0x00000040
end_define

begin_define
define|#
directive|define
name|IGNCR
value|0x00000080
end_define

begin_define
define|#
directive|define
name|ICRNL
value|0x00000100
end_define

begin_define
define|#
directive|define
name|IXON
value|0x00000400
end_define

begin_define
define|#
directive|define
name|IXANY
value|0x00000800
end_define

begin_define
define|#
directive|define
name|IXOFF
value|0x00001000
end_define

begin_comment
comment|/* output modes */
end_comment

begin_define
define|#
directive|define
name|OPOST
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ONLCR
value|0x00000004
end_define

begin_comment
comment|/* control modes */
end_comment

begin_define
define|#
directive|define
name|CSIZE
value|0x00000030
end_define

begin_define
define|#
directive|define
name|CS5
value|0x00000000
end_define

begin_define
define|#
directive|define
name|CS6
value|0x00000010
end_define

begin_define
define|#
directive|define
name|CS7
value|0x00000020
end_define

begin_define
define|#
directive|define
name|CS8
value|0x00000030
end_define

begin_define
define|#
directive|define
name|CSTOPB
value|0x00000040
end_define

begin_define
define|#
directive|define
name|CREAD
value|0x00000080
end_define

begin_define
define|#
directive|define
name|PARENB
value|0x00000100
end_define

begin_define
define|#
directive|define
name|PARODD
value|0x00000200
end_define

begin_define
define|#
directive|define
name|HUPCL
value|0x00000400
end_define

begin_define
define|#
directive|define
name|CLOCAL
value|0x00000800
end_define

begin_comment
comment|/* line discipline modes */
end_comment

begin_define
define|#
directive|define
name|ISIG
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ICANON
value|0x00000002
end_define

begin_define
define|#
directive|define
name|_TERMIOS_ECHO
value|0x00000008
end_define

begin_define
define|#
directive|define
name|ECHO
value|_TERMIOS_ECHO
end_define

begin_define
define|#
directive|define
name|ECHOE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ECHOK
value|0x00000020
end_define

begin_define
define|#
directive|define
name|ECHONL
value|0x00000040
end_define

begin_define
define|#
directive|define
name|_TERMIOS_NOFLSH
value|0x00000080
end_define

begin_define
define|#
directive|define
name|NOFLSH
value|_TERMIOS_NOFLSH
end_define

begin_define
define|#
directive|define
name|_TERMIOS_TOSTOP
value|0x00000100
end_define

begin_define
define|#
directive|define
name|TOSTOP
value|_TERMIOS_TOSTOP
end_define

begin_define
define|#
directive|define
name|IEXTEN
value|0x00008000
end_define

begin_comment
comment|/* tcsetattr() actions */
end_comment

begin_define
define|#
directive|define
name|TCSANOW
value|0
end_define

begin_define
define|#
directive|define
name|TCSADRAIN
value|1
end_define

begin_define
define|#
directive|define
name|TCSAFLUSH
value|2
end_define

begin_struct
struct|struct
name|termios
block|{
name|struct
name|sgttyb
name|__sg
decl_stmt|;
name|struct
name|tchars
name|__tc
decl_stmt|;
name|struct
name|ltchars
name|__ltc
decl_stmt|;
name|tcflag_t
name|c_iflag
decl_stmt|;
comment|/* input modes */
name|tcflag_t
name|c_oflag
decl_stmt|;
comment|/* output modes */
name|tcflag_t
name|c_cflag
decl_stmt|;
comment|/* control modes */
name|tcflag_t
name|c_lflag
decl_stmt|;
comment|/* local modes */
name|cc_t
name|c_cc
index|[
name|NCCS
index|]
decl_stmt|;
comment|/* control chars */
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|int
name|tcgetattr
parameter_list|(
comment|/* int fd, struct termios *t */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tcsetattr
parameter_list|(
comment|/* int fd, int action, struct termios *t */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|speed_t
name|cfgetospeed
parameter_list|(
comment|/* struct termios *t */
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _termios_h_ */
end_comment

end_unit

