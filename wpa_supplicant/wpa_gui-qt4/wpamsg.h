begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * wpa_gui - WpaMsg class for storing event messages  * Copyright (c) 2005-2006, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WPAMSG_H
end_ifndef

begin_define
define|#
directive|define
name|WPAMSG_H
end_define

begin_include
include|#
directive|include
file|<QDateTime>
end_include

begin_include
include|#
directive|include
file|<QLinkedList>
end_include

begin_decl_stmt
name|class
name|WpaMsg
block|{
name|public
label|:
name|WpaMsg
argument_list|(
argument|const QString&_msg
argument_list|,
argument|int _priority =
literal|2
argument_list|)
block|:
name|msg
argument_list|(
name|_msg
argument_list|)
operator|,
name|priority
argument_list|(
argument|_priority
argument_list|)
block|{
name|timestamp
operator|=
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
block|; 	}
name|QString
name|getMsg
argument_list|()
specifier|const
block|{
return|return
name|msg
return|;
block|}
name|int
name|getPriority
argument_list|()
specifier|const
block|{
return|return
name|priority
return|;
block|}
name|QDateTime
name|getTimestamp
argument_list|()
specifier|const
block|{
return|return
name|timestamp
return|;
block|}
name|private
label|:
name|QString
name|msg
decl_stmt|;
name|int
name|priority
decl_stmt|;
name|QDateTime
name|timestamp
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_typedef
typedef|typedef
name|QLinkedList
operator|<
name|WpaMsg
operator|>
name|WpaMsgList
expr_stmt|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WPAMSG_H */
end_comment

end_unit

