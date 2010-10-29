begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * wpa_gui - StringQuery class  * Copyright (c) 2009, Atheros Communications  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STRINGQUERY_H
end_ifndef

begin_define
define|#
directive|define
name|STRINGQUERY_H
end_define

begin_include
include|#
directive|include
file|<QDialog>
end_include

begin_include
include|#
directive|include
file|<QLineEdit>
end_include

begin_include
include|#
directive|include
file|<QGridLayout>
end_include

begin_decl_stmt
name|class
name|StringQuery
range|:
name|public
name|QDialog
block|{
name|Q_OBJECT
name|public
operator|:
name|StringQuery
argument_list|(
argument|QString label
argument_list|)
block|;
name|QString
name|get_string
argument_list|()
block|;
name|private
operator|:
name|QLineEdit
operator|*
name|edit
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STRINGQUERY_H */
end_comment

end_unit

