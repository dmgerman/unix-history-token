begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* aliasbr.h - definitions for the aliasing system */
end_comment

begin_comment
comment|/* $Id: aliasbr.h,v 1.2 1992/05/12 22:03:31 jromine Exp $ */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|AliasFile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mh-alias(5) */
end_comment

begin_define
define|#
directive|define
name|PASSWD
value|"/etc/passwd"
end_define

begin_comment
comment|/* passwd(5) */
end_comment

begin_define
define|#
directive|define
name|GROUP
value|"/etc/group"
end_define

begin_comment
comment|/* group(5) */
end_comment

begin_define
define|#
directive|define
name|EVERYONE
value|200
end_define

begin_comment
comment|/* lowest uid for everyone */
end_comment

begin_struct
struct|struct
name|aka
block|{
name|char
modifier|*
name|ak_name
decl_stmt|;
comment|/* name to match against */
name|struct
name|adr
modifier|*
name|ak_addr
decl_stmt|;
comment|/* list of addresses that it maps to */
name|struct
name|aka
modifier|*
name|ak_next
decl_stmt|;
comment|/* next aka in list */
name|char
name|ak_visible
decl_stmt|;
comment|/* should be visible in headers */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|adr
block|{
name|char
modifier|*
name|ad_text
decl_stmt|;
comment|/* text of this address in list */
name|struct
name|adr
modifier|*
name|ad_next
decl_stmt|;
comment|/* next adr in list */
name|char
name|ad_local
decl_stmt|;
comment|/* text is local (check for expansion) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|home
block|{
comment|/* incore version of /etc/passwd */
name|char
modifier|*
name|h_name
decl_stmt|;
comment|/* user name */
name|int
name|h_uid
decl_stmt|;
comment|/* user id */
name|int
name|h_gid
decl_stmt|;
comment|/* user's group */
name|char
modifier|*
name|h_home
decl_stmt|;
comment|/* user's home directory */
name|char
modifier|*
name|h_shell
decl_stmt|;
comment|/* user's shell */
ifdef|#
directive|ifdef
name|BSD42
name|int
name|h_ngrps
decl_stmt|;
comment|/* number of groups this user belongs to */
endif|#
directive|endif
comment|/* BSD42 */
name|struct
name|home
modifier|*
name|h_next
decl_stmt|;
comment|/* next home in list */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|MMDFMTS
end_ifndef

begin_function_decl
name|struct
name|home
modifier|*
name|seek_home
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MMDFMTS */
end_comment

begin_decl_stmt
name|int
name|alias
argument_list|()
decl_stmt|,
name|akvisible
argument_list|()
decl_stmt|,
name|init_pw
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|akresult
argument_list|()
decl_stmt|,
modifier|*
name|akvalue
argument_list|()
decl_stmt|,
modifier|*
name|akerror
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* codes returned by alias() */
end_comment

begin_define
define|#
directive|define
name|AK_OK
value|0
end_define

begin_comment
comment|/* file parsed ok 	 */
end_comment

begin_define
define|#
directive|define
name|AK_NOFILE
value|1
end_define

begin_comment
comment|/* couldn't read file 	 */
end_comment

begin_define
define|#
directive|define
name|AK_ERROR
value|2
end_define

begin_comment
comment|/* error parsing file 	 */
end_comment

begin_define
define|#
directive|define
name|AK_LIMIT
value|3
end_define

begin_comment
comment|/* memory limit exceeded */
end_comment

begin_define
define|#
directive|define
name|AK_NOGROUP
value|4
end_define

begin_comment
comment|/* no such group 	 */
end_comment

begin_comment
comment|/* should live here, not in mts.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Everyone
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|NoShell
decl_stmt|;
end_decl_stmt

end_unit

