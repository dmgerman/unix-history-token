begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * $FreeBSD$  * $Source: /usr/sww/share/src/kerberosIV.BSD/include/RCS/rkinit.h,v $  * $Author: dglo $  *  * Main header file for rkinit library users  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__RKINIT_H__
end_ifndef

begin_define
define|#
directive|define
name|__RKINIT_H__
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SABER
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|LOCORE
argument_list|)
operator|&&
name|defined
argument_list|(
name|RCS_HDRS
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid_rkinit_h
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint || SABER || LOCORE || RCS_HDRS */
end_comment

begin_include
include|#
directive|include
file|<krb.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|RK_PROTO
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RK_PROTO
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
comment|/* __STDC__ */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|aname
index|[
name|ANAME_SZ
operator|+
literal|1
index|]
decl_stmt|;
name|char
name|inst
index|[
name|INST_SZ
operator|+
literal|1
index|]
decl_stmt|;
name|char
name|realm
index|[
name|REALM_SZ
operator|+
literal|1
index|]
decl_stmt|;
name|char
name|sname
index|[
name|ANAME_SZ
operator|+
literal|1
index|]
decl_stmt|;
name|char
name|sinst
index|[
name|INST_SZ
operator|+
literal|1
index|]
decl_stmt|;
name|char
name|username
index|[
literal|9
index|]
decl_stmt|;
comment|/* max local name length + 1 */
name|char
name|tktfilename
index|[
name|MAXPATHLEN
operator|+
literal|1
index|]
decl_stmt|;
name|u_int
name|lifetime
decl_stmt|;
block|}
name|rkinit_info
typedef|;
end_typedef

begin_define
define|#
directive|define
name|RKINIT_SUCCESS
value|0
end_define

begin_comment
comment|/* Function declarations */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rkinit
name|RK_PROTO
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|rkinit_info
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rkinit_errmsg
name|RK_PROTO
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __RKINIT_H__ */
end_comment

end_unit

