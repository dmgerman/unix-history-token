begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * wpa_gui - UserDataRequest class  * Copyright (c) 2005-2006, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USERDATAREQUEST_H
end_ifndef

begin_define
define|#
directive|define
name|USERDATAREQUEST_H
end_define

begin_include
include|#
directive|include
file|<QObject>
end_include

begin_include
include|#
directive|include
file|"ui_userdatarequest.h"
end_include

begin_decl_stmt
name|class
name|WpaGui
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|UserDataRequest
range|:
name|public
name|QDialog
decl_stmt|,
name|public
name|Ui
decl|::
name|UserDataRequest
block|{
name|Q_OBJECT
name|public
range|:
name|UserDataRequest
argument_list|(
argument|QWidget *parent =
literal|0
argument_list|,
argument|const char *name =
literal|0
argument_list|,
argument|bool modal = false
argument_list|,
argument|Qt::WFlags fl =
literal|0
argument_list|)
decl_stmt|;
operator|~
name|UserDataRequest
argument_list|()
expr_stmt|;
name|int
name|setParams
parameter_list|(
name|WpaGui
modifier|*
name|_wpagui
parameter_list|,
specifier|const
name|char
modifier|*
name|reqMsg
parameter_list|)
function_decl|;
name|public
name|slots
range|:
name|virtual
name|void
name|sendReply
argument_list|()
decl_stmt|;
name|protected
name|slots
range|:
name|virtual
name|void
name|languageChange
argument_list|()
decl_stmt|;
name|private
label|:
name|WpaGui
modifier|*
name|wpagui
decl_stmt|;
name|int
name|networkid
decl_stmt|;
name|QString
name|field
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USERDATAREQUEST_H */
end_comment

end_unit

