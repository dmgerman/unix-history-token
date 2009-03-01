begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * wpa_gui - AddInterface class  * Copyright (c) 2008, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ADDINTERFACE_H
end_ifndef

begin_define
define|#
directive|define
name|ADDINTERFACE_H
end_define

begin_include
include|#
directive|include
file|<QObject>
end_include

begin_include
include|#
directive|include
file|<QtGui/QDialog>
end_include

begin_include
include|#
directive|include
file|<QtGui/QTreeWidget>
end_include

begin_include
include|#
directive|include
file|<QtGui/QVBoxLayout>
end_include

begin_decl_stmt
name|class
name|WpaGui
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|AddInterface
range|:
name|public
name|QDialog
block|{
name|Q_OBJECT
name|public
operator|:
name|AddInterface
argument_list|(
name|WpaGui
operator|*
name|_wpagui
argument_list|,
name|QWidget
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|public
name|slots
operator|:
name|virtual
name|void
name|interfaceSelected
argument_list|(
name|QTreeWidgetItem
operator|*
name|sel
argument_list|)
block|;
name|private
operator|:
name|void
name|addInterfaces
argument_list|()
block|;
name|bool
name|addRegistryInterface
argument_list|(
specifier|const
name|QString
operator|&
name|ifname
argument_list|)
block|;
name|QVBoxLayout
operator|*
name|vboxLayout
block|;
name|QTreeWidget
operator|*
name|interfaceWidget
block|;
name|WpaGui
operator|*
name|wpagui
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ADDINTERFACE_H */
end_comment

end_unit

