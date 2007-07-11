begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * wpa_gui - ScanResults class  * Copyright (c) 2005-2006, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SCANRESULTS_H
end_ifndef

begin_define
define|#
directive|define
name|SCANRESULTS_H
end_define

begin_include
include|#
directive|include
file|<QObject>
end_include

begin_include
include|#
directive|include
file|"ui_scanresults.h"
end_include

begin_decl_stmt
name|class
name|WpaGui
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|ScanResults
range|:
name|public
name|QDialog
decl_stmt|,
name|public
name|Ui
decl|::
name|ScanResults
block|{
name|Q_OBJECT
name|public
range|:
name|ScanResults
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
name|ScanResults
argument_list|()
expr_stmt|;
name|public
name|slots
range|:
name|virtual
name|void
name|setWpaGui
argument_list|(
name|WpaGui
operator|*
name|_wpagui
argument_list|)
decl_stmt|;
name|virtual
name|void
name|updateResults
parameter_list|()
function_decl|;
name|virtual
name|void
name|scanRequest
parameter_list|()
function_decl|;
name|virtual
name|void
name|getResults
parameter_list|()
function_decl|;
name|virtual
name|void
name|bssSelected
parameter_list|(
name|Q3ListViewItem
modifier|*
name|sel
parameter_list|)
function_decl|;
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
name|QTimer
modifier|*
name|timer
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
comment|/* SCANRESULTS_H */
end_comment

end_unit

