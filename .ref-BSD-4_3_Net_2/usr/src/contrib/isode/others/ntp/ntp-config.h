begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* config file for ntp compilation */
end_comment

begin_define
define|#
directive|define
name|SUN_FLT_BUG
end_define

begin_comment
comment|/* sun 3 problems*/
end_comment

begin_define
define|#
directive|define
name|SUN_3_3
end_define

begin_comment
comment|/* Sun 3.3 strangeness */
end_comment

begin_define
define|#
directive|define
name|SETTICKADJ
end_define

begin_comment
comment|/* attempt to modify kernel's `tickadj' 				   variable at run time */
end_comment

begin_define
define|#
directive|define
name|DEBUG
end_define

begin_comment
comment|/* enable optional debugging trace */
end_comment

begin_define
define|#
directive|define
name|REFCLOCK
end_define

begin_comment
comment|/* define if you have a reference clock 				   attached to your machine.  (untested 				   by UMD) */
end_comment

begin_undef
undef|#
directive|undef
name|BROADCAST_NTP
end_undef

begin_comment
comment|/* experimental support for broadcast NTP */
end_comment

begin_undef
undef|#
directive|undef
name|XADJTIME2
end_undef

begin_comment
comment|/* experimental support for second-order 				   clock adjustment  */
end_comment

begin_undef
undef|#
directive|undef
name|PSTI
end_undef

begin_comment
comment|/* define along with REFCLOCK if you have 				   a PSTI clock attached that you'd like 				   to use a a reference clock */
end_comment

begin_undef
undef|#
directive|undef
name|XTAL
name|1
end_undef

begin_comment
comment|/* 0 for line freq clock, or 				   1 for crystal controlled clock (default)*/
end_comment

begin_undef
undef|#
directive|undef
name|NOSWAP
end_undef

begin_comment
comment|/* allow use of plock() to prevent swapping */
end_comment

begin_comment
comment|/* if you dont have random/srandom - use the below workaround */
end_comment

begin_comment
comment|/* #define srandom(x) srand(x) #define random()	rand() */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WAYTOOBIG
end_ifndef

begin_define
define|#
directive|define
name|WAYTOOBIG
value|1000.0
end_define

begin_comment
comment|/* Too many seconds to correct, something is 				 * really wrong */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|XTAL
end_ifndef

begin_define
define|#
directive|define
name|XTAL
value|1
end_define

begin_comment
comment|/* crystal controlled clock by default */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NTPINITFILE
end_ifndef

begin_define
define|#
directive|define
name|NTPINITFILE
value|"/usr/adm/ntp.conf"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NTPDRIFTCOMP
end_ifndef

begin_define
define|#
directive|define
name|NTPDRIFTCOMP
value|"/usr/adm/ntp.drift"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

