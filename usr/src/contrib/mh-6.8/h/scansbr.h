begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* scansbr.h - definitions for scan () */
end_comment

begin_comment
comment|/* $Id: scansbr.h,v 1.7 1992/11/10 17:27:11 jromine Exp $ */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|scanl
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SCNENC
value|2
end_define

begin_comment
comment|/* message just fine, but encrypted(!!) */
end_comment

begin_define
define|#
directive|define
name|SCNMSG
value|1
end_define

begin_comment
comment|/* message just fine */
end_comment

begin_define
define|#
directive|define
name|SCNEOF
value|0
end_define

begin_comment
comment|/* empty message */
end_comment

begin_define
define|#
directive|define
name|SCNERR
value|(-1)
end_define

begin_comment
comment|/* error message */
end_comment

begin_define
define|#
directive|define
name|SCNNUM
value|(-2)
end_define

begin_comment
comment|/* number out of range */
end_comment

begin_define
define|#
directive|define
name|SCNFAT
value|(-3)
end_define

begin_comment
comment|/* fatal error */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UK
end_ifndef

begin_define
define|#
directive|define
name|FORMAT
define|\
value|"%4(msg)%<(cur)+%| %>%<{replied}-%?{encrypted}E%| %>\ %02(mon{date})/%02(mday{date})%<{date} %|*%>\ %<(mymbox{from})%<{to}To:%14(friendly{to})%>%>%<(zero)%17(friendly{from})%>  \ %{subject}%<{body}<<%{body}>>%>\n"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* UK */
end_comment

begin_define
define|#
directive|define
name|FORMAT
define|\
value|"%4(msg)%<(cur)+%| %>%<{replied}-%?{encrypted}E%| %>\ %02(mday{date})/%02(mon{date})%<{date} %|*%>\ %<(mymbox{from})%<{to}To:%14(friendly{to})%>%>%<(zero)%17(friendly{from})%>  \ %{subject}%<{body}<<%{body}>>%>\n"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UK */
end_comment

begin_define
define|#
directive|define
name|WIDTH
value|78
end_define

begin_function_decl
name|int
name|scan
parameter_list|()
function_decl|;
end_function_decl

end_unit

