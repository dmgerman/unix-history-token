begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)condevs.h	4.7	(Berkeley)	5/5/88	*/
end_comment

begin_include
include|#
directive|include
file|"uucp.h"
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|VMSDTR
end_ifdef

begin_comment
comment|/* Modem control on vms(works dtr) */
end_comment

begin_include
include|#
directive|include
file|<eunice/eunice.h>
end_include

begin_define
define|#
directive|define
name|TT$M_MODEM
value|0x00200000
end_define

begin_comment
comment|/* These should be in a '.h' somewhere */
end_comment

begin_define
define|#
directive|define
name|SS$_NORMAL
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IO$_SETMODE
value|0x00000023
end_define

begin_define
define|#
directive|define
name|IO$_SENSEMODE
value|0x00000027
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
name|devSel
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name to pass to delock() in close */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|,
name|next_fd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|jmp_buf
name|Sjbuf
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|alarmtr
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|nulldev
argument_list|()
decl_stmt|,
name|nodev
argument_list|()
decl_stmt|,
name|Acuopn
argument_list|()
decl_stmt|,
name|diropn
argument_list|()
decl_stmt|,
name|dircls
argument_list|()
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DATAKIT
end_ifdef

begin_function_decl
name|int
name|dkopn
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
endif|DATAKIT
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DN11
end_ifdef

begin_decl_stmt
name|int
name|dnopn
argument_list|()
decl_stmt|,
name|dncls
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|DN11
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAYES
end_ifdef

begin_decl_stmt
name|int
name|hyspopn
argument_list|()
decl_stmt|,
name|hystopn
argument_list|()
decl_stmt|,
name|hyscls
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|HAYES
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAYES2400
end_ifdef

begin_decl_stmt
name|int
name|hyspopn24
argument_list|()
decl_stmt|,
name|hystopn24
argument_list|()
decl_stmt|,
name|hyscls24
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|HAYES2400
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAYESQ
end_ifdef

begin_decl_stmt
name|int
name|hysqopn
argument_list|()
decl_stmt|,
name|hysqcls
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a version of hayes that doesn't use ret codes */
end_comment

begin_endif
endif|#
directive|endif
endif|HAYESQ
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NOVATION
end_ifdef

begin_decl_stmt
name|int
name|novopn
argument_list|()
decl_stmt|,
name|novcls
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|NOVATION
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CDS224
end_ifdef

begin_decl_stmt
name|int
name|cdsopn224
argument_list|()
decl_stmt|,
name|cdscls224
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|CDs224
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DF02
end_ifdef

begin_decl_stmt
name|int
name|df2opn
argument_list|()
decl_stmt|,
name|df2cls
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|DF02
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DF112
end_ifdef

begin_decl_stmt
name|int
name|df12popn
argument_list|()
decl_stmt|,
name|df12topn
argument_list|()
decl_stmt|,
name|df12cls
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|DF112
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PNET
end_ifdef

begin_function_decl
name|int
name|pnetopn
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
endif|PNET
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VENTEL
end_ifdef

begin_decl_stmt
name|int
name|ventopn
argument_list|()
decl_stmt|,
name|ventcls
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|VENTEL
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PENRIL
end_ifdef

begin_decl_stmt
name|int
name|penopn
argument_list|()
decl_stmt|,
name|pencls
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|PENRIL
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|UNETTCP
end_ifdef

begin_define
define|#
directive|define
name|TO_ACTIVE
value|0
end_define

begin_decl_stmt
name|int
name|unetopn
argument_list|()
decl_stmt|,
name|unetcls
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|UNETTCP
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BSDTCP
end_ifdef

begin_decl_stmt
name|int
name|bsdtcpopn
argument_list|()
decl_stmt|,
name|bsdtcpcls
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|BSDTCP
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VADIC
end_ifdef

begin_decl_stmt
name|int
name|vadopn
argument_list|()
decl_stmt|,
name|vadcls
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|VADIC
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VA212
end_ifdef

begin_decl_stmt
name|int
name|va212opn
argument_list|()
decl_stmt|,
name|va212cls
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|VA212
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VA811S
end_ifdef

begin_decl_stmt
name|int
name|va811opn
argument_list|()
decl_stmt|,
name|va811cls
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|VA811S
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VA820
end_ifdef

begin_decl_stmt
name|int
name|va820opn
argument_list|()
decl_stmt|,
name|va820cls
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|VA820
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|RVMACS
end_ifdef

begin_decl_stmt
name|int
name|rvmacsopn
argument_list|()
decl_stmt|,
name|rvmacscls
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VMACS
end_ifdef

begin_decl_stmt
name|int
name|vmacsopn
argument_list|()
decl_stmt|,
name|vmacscls
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MICOM
end_ifdef

begin_decl_stmt
name|int
name|micopn
argument_list|()
decl_stmt|,
name|miccls
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|MICOM
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SYTEK
end_ifdef

begin_decl_stmt
name|int
name|sykopn
argument_list|()
decl_stmt|,
name|sykcls
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|SYTEK
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ATT2224
end_ifdef

begin_decl_stmt
name|int
name|attopn
argument_list|()
decl_stmt|,
name|attcls
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|ATT2224
end_endif

end_unit

