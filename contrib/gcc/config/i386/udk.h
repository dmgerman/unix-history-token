begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for i386 interfacing with SCO's Universal Development Kit    probably running on OpenServer 5, Unixware 2, or Unixware 5  */
end_comment

begin_comment
comment|/* We're very much the SVR4 target with "/udk" prepended to everything that's    interesting */
end_comment

begin_include
include|#
directive|include
file|"i386/sysv5.h"
end_include

begin_undef
undef|#
directive|undef
name|MD_EXEC_PREFIX
end_undef

begin_define
define|#
directive|define
name|MD_EXEC_PREFIX
value|"/udk/usr/ccs/bin/"
end_define

begin_undef
undef|#
directive|undef
name|MD_STARTFILE_PREFIX
end_undef

begin_define
define|#
directive|define
name|MD_STARTFILE_PREFIX
value|"/udk/usr/ccs/lib/"
end_define

begin_define
define|#
directive|define
name|STANDARD_INCLUDE_DIR
value|"/udk/usr/include"
end_define

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{h*} %{v:-V} \ 	%{b} %{Wl,*:%*} \ 	%{static:-dn -Bstatic} \ 	%{shared:-G -dy -z text} \ 	%{symbolic:-Bsymbolic -G -dy -z text} \ 	%{G:-G} \ 	%{YP,*} \ 	%{!YP,*:%{p:-Y P,/udk/usr/ccs/lib/libp:/udk/usr/lib/libp:/udk/usr/ccs/lib:/udk/usr/lib} \ 	%{!p:-Y P,/udk/usr/ccs/lib:/udk/usr/lib}} \ 	%{Qy:} %{!Qn:-Qy}"
end_define

end_unit

