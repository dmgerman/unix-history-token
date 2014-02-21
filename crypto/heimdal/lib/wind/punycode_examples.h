begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ./punycode_examples.h */
end_comment

begin_comment
comment|/* Automatically generated at 2012-01-11T14:07:08.539140 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PUNYCODE_EXAMPLES_H
end_ifndef

begin_define
define|#
directive|define
name|PUNYCODE_EXAMPLES_H
value|1
end_define

begin_include
include|#
directive|include
file|<krb5-types.h>
end_include

begin_define
define|#
directive|define
name|MAX_LENGTH
value|40
end_define

begin_struct
struct|struct
name|punycode_example
block|{
name|size_t
name|len
decl_stmt|;
name|uint32_t
name|val
index|[
name|MAX_LENGTH
index|]
decl_stmt|;
specifier|const
name|char
modifier|*
name|pc
decl_stmt|;
specifier|const
name|char
modifier|*
name|description
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|punycode_example
name|punycode_examples
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|size_t
name|punycode_examples_size
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PUNYCODE_EXAMPLES_H */
end_comment

end_unit

