begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*$Header: /p/tcsh/cvsroot/tcsh/win32/version.h,v 1.24 2008/09/10 20:34:21 amold Exp $*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VERSION_H
end_ifndef

begin_define
define|#
directive|define
name|VERSION_H
end_define

begin_comment
comment|/* remember to change both instance of the version -amol */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NTDBG
end_ifdef

begin_define
define|#
directive|define
name|LOCALSTR
value|",nt-rev-8.10-debug"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LOCALSTR
value|",nt-rev-8.10"
end_define

begin_comment
comment|//patches
end_comment

begin_endif
endif|#
directive|endif
endif|NTDBG
end_endif

begin_endif
endif|#
directive|endif
endif|VERSION_H
end_endif

end_unit

