begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// dirsearch.h -- directory searching for gold  -*- C++ -*-
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GOLD_DIRSEARCH_H
end_ifndef

begin_define
define|#
directive|define
name|GOLD_DIRSEARCH_H
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<list>
end_include

begin_include
include|#
directive|include
file|"workqueue.h"
end_include

begin_decl_stmt
name|namespace
name|gold
block|{
name|class
name|General_options
decl_stmt|;
comment|// A simple interface to manage directories to be searched for
comment|// libraries.
name|class
name|Dirsearch
block|{
name|public
label|:
name|Dirsearch
argument_list|()
expr_stmt|;
comment|// Add a directory to the search path.
name|void
name|add
parameter_list|(
name|Workqueue
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
comment|// Add a list of directories to the search path.
name|void
name|add
argument_list|(
name|Workqueue
operator|*
argument_list|,
specifier|const
name|General_options
operator|::
name|Dir_list
operator|&
argument_list|)
decl_stmt|;
comment|// Search for a file, giving one or two names to search for (the
comment|// second one may be empty).  Return a full path name for the file,
comment|// or the empty string if it could not be found.  This may only be
comment|// called if the token is not blocked.
name|std
operator|::
name|string
name|find
argument_list|(
argument|const std::string&
argument_list|,
argument|const std::string& n2 = std::string()
argument_list|)
specifier|const
expr_stmt|;
comment|// Return a reference to the blocker token which controls access.
specifier|const
name|Task_token
operator|&
name|token
argument_list|()
specifier|const
block|{
return|return
name|this
operator|->
name|token_
return|;
block|}
name|private
label|:
comment|// We can not copy this class.
name|Dirsearch
argument_list|(
specifier|const
name|Dirsearch
operator|&
argument_list|)
expr_stmt|;
name|Dirsearch
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Dirsearch
operator|&
operator|)
decl_stmt|;
comment|// Directories to search.
name|std
operator|::
name|list
operator|<
specifier|const
name|char
operator|*
operator|>
name|directories_
expr_stmt|;
comment|// Blocker token to control access from tasks.
name|Task_token
name|token_
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End namespace gold.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !defined(GOLD_DIRSEARCH_H)
end_comment

end_unit

