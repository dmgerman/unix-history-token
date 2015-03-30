begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * declcond.h - declarations conditionalized for ntpd  *  * The NTP reference implementation distribution includes two distinct  * declcond.h files, one in ntpd/ used only by ntpd, and another in  * include/ used by libntp and utilities.  This relies on the source  * file's directory being ahead of include/ in the include search.  *  * The ntpd variant of declcond.h declares "debug" only #ifdef DEBUG,  * as the --disable-debugging version of ntpd should not reference  * "debug".  The libntp and utilities variant always declares debug,  * as it is used in those codebases even without DEBUG defined.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DECLCOND_H
end_ifndef

begin_define
define|#
directive|define
name|DECLCOND_H
end_define

begin_comment
comment|/* #ifdef DEBUG */
end_comment

begin_comment
comment|/* uncommented in ntpd/declcond.h */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* #endif */
end_comment

begin_comment
comment|/* uncommented in ntpd/declcond.h */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DECLCOND_H */
end_comment

end_unit

