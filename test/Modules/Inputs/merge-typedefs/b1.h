begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|B1_H
end_ifndef

begin_define
define|#
directive|define
name|B1_H
end_define

begin_typedef
typedef|typedef
struct|struct
block|{}
name|foo_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|foo_t
name|foo2_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|"a2.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineBasicBlock
decl_stmt|;
name|template
operator|<
name|class
name|NodeT
operator|>
name|class
name|DomTreeNodeBase
expr_stmt|;
typedef|typedef
name|DomTreeNodeBase
operator|<
name|MachineBasicBlock
operator|>
name|MachineDomTreeNode
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

