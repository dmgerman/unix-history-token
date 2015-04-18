begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Hotspot 2.0 client - Web browser  * Copyright (c) 2013, Qualcomm Atheros, Inc.  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BROWSER_H
end_ifndef

begin_define
define|#
directive|define
name|BROWSER_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_NO_BROWSER
end_ifdef

begin_function
specifier|static
specifier|inline
name|int
name|hs20_web_browser
parameter_list|(
specifier|const
name|char
modifier|*
name|url
parameter_list|)
block|{
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CONFIG_NO_BROWSER */
end_comment

begin_function_decl
name|int
name|hs20_web_browser
parameter_list|(
specifier|const
name|char
modifier|*
name|url
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_NO_BROWSER */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BROWSER_H */
end_comment

end_unit

