begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * @(#) inetcf.h 1.1 94/12/28 17:42:30   *    * Author: Wietse Venema, Eindhoven University of Technology, The Netherlands.   */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|inet_cfg
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* read inetd.conf file */
end_comment

begin_function_decl
specifier|extern
name|void
name|inet_set
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* remember internet service */
end_comment

begin_function_decl
specifier|extern
name|int
name|inet_get
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* look up internet service */
end_comment

begin_define
define|#
directive|define
name|WR_UNKNOWN
value|(-1)
end_define

begin_comment
comment|/* service unknown */
end_comment

begin_define
define|#
directive|define
name|WR_NOT
value|1
end_define

begin_comment
comment|/* may not be wrapped */
end_comment

begin_define
define|#
directive|define
name|WR_MAYBE
value|2
end_define

begin_comment
comment|/* may be wrapped */
end_comment

begin_define
define|#
directive|define
name|WR_YES
value|3
end_define

begin_comment
comment|/* service is wrapped */
end_comment

end_unit

