begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * wpa_gui - EventHistory class  * Copyright (c) 2005-2006, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EVENTHISTORY_H
end_ifndef

begin_define
define|#
directive|define
name|EVENTHISTORY_H
end_define

begin_include
include|#
directive|include
file|<QObject>
end_include

begin_include
include|#
directive|include
file|"ui_eventhistory.h"
end_include

begin_decl_stmt
name|class
name|EventListModel
range|:
name|public
name|QAbstractTableModel
block|{
name|Q_OBJECT
name|public
operator|:
name|EventListModel
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
operator|:
name|QAbstractTableModel
argument_list|(
argument|parent
argument_list|)
block|{}
name|int
name|rowCount
argument_list|(
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
specifier|const
block|;
name|int
name|columnCount
argument_list|(
argument|const QModelIndex&parent = QModelIndex()
argument_list|)
specifier|const
block|;
name|QVariant
name|data
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|int role
argument_list|)
specifier|const
block|;
name|QVariant
name|headerData
argument_list|(
argument|int section
argument_list|,
argument|Qt::Orientation orientation
argument_list|,
argument|int role = Qt::DisplayRole
argument_list|)
specifier|const
block|;
name|void
name|addEvent
argument_list|(
argument|QString time
argument_list|,
argument|QString msg
argument_list|)
block|;
name|private
operator|:
name|QStringList
name|timeList
block|;
name|QStringList
name|msgList
block|; }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|EventHistory
range|:
name|public
name|QDialog
decl_stmt|,
name|public
name|Ui
decl|::
name|EventHistory
block|{
name|Q_OBJECT
name|public
range|:
name|EventHistory
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
name|EventHistory
argument_list|()
expr_stmt|;
name|public
name|slots
range|:
name|virtual
name|void
name|addEvents
argument_list|(
argument|WpaMsgList msgs
argument_list|)
decl_stmt|;
name|virtual
name|void
name|addEvent
parameter_list|(
name|WpaMsg
name|msg
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
name|EventListModel
modifier|*
name|elm
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
comment|/* EVENTHISTORY_H */
end_comment

end_unit

