begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 David I. Bell  * Permission is granted to use, distribute, or modify this source,  * provided that this copyright notice remains intact.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LABEL_H
end_ifndef

begin_define
define|#
directive|define
name|LABEL_H
end_define

begin_include
include|#
directive|include
file|"zmath.h"
end_include

begin_define
define|#
directive|define
name|NULL_LABEL
value|((LABEL *) 0)
end_define

begin_comment
comment|/*  * Label structures.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|l_offset
decl_stmt|;
comment|/* offset into code of label */
name|long
name|l_chain
decl_stmt|;
comment|/* offset into code of undefined chain */
name|char
modifier|*
name|l_name
decl_stmt|;
comment|/* name of label if any */
block|}
name|LABEL
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|void
name|initlabels
name|MATH_PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|definelabel
name|MATH_PROTO
argument_list|(
operator|(
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|addlabel
name|MATH_PROTO
argument_list|(
operator|(
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|clearlabel
name|MATH_PROTO
argument_list|(
operator|(
name|LABEL
operator|*
name|lp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|setlabel
name|MATH_PROTO
argument_list|(
operator|(
name|LABEL
operator|*
name|lp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|uselabel
name|MATH_PROTO
argument_list|(
operator|(
name|LABEL
operator|*
name|lp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|checklabels
name|MATH_PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* END CODE */
end_comment

end_unit

