begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ftprc.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ftprc_h_
end_ifndef

begin_define
define|#
directive|define
name|_ftprc_h_
end_define

begin_comment
comment|/*  $RCSfile: ftprc.h,v $  *  $Revision: 14020.11 $  *  $Date: 93/05/21 05:45:31 $  */
end_comment

begin_define
define|#
directive|define
name|NETRC
value|"netrc"
end_define

begin_define
define|#
directive|define
name|FTPRC
value|"ncftprc"
end_define

begin_define
define|#
directive|define
name|RC_DELIM
value|" \n\t,"
end_define

begin_typedef
typedef|typedef
name|struct
name|site
modifier|*
name|siteptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|site
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name (or IP address) of site */
name|siteptr
name|next
decl_stmt|;
block|}
name|site
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|recentsite
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* name (or IP address) of site */
name|char
modifier|*
name|dir
decl_stmt|;
comment|/* directory we were in last time we called. */
name|time_t
name|lastcall
decl_stmt|;
comment|/* when this site was called last. */
block|}
name|recentsite
typedef|;
end_typedef

begin_function_decl
name|int
name|thrash_rc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AddNewSitePtr
parameter_list|(
name|char
modifier|*
name|word
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ruserpass2
parameter_list|(
name|char
modifier|*
name|host
parameter_list|,
name|char
modifier|*
modifier|*
name|user
parameter_list|,
name|char
modifier|*
modifier|*
name|pass
parameter_list|,
name|char
modifier|*
modifier|*
name|acct
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|GetFullSiteName
parameter_list|(
name|char
modifier|*
name|host
parameter_list|,
name|char
modifier|*
name|lastdir
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ReadRecentSitesFile
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|WriteRecentSitesFile
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AddRecentSite
parameter_list|(
name|char
modifier|*
name|host
parameter_list|,
name|char
modifier|*
name|lastdir
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|UpdateRecentSitesList
parameter_list|(
name|char
modifier|*
name|host
parameter_list|,
name|char
modifier|*
name|lastdir
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PrintSiteList
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* eof */
end_comment

end_unit

