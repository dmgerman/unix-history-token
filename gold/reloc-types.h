begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// reloc-types.h -- ELF relocation templates for gold  -*- C++ -*-
end_comment

begin_comment
comment|// This header files defines a few convenient templated types for use
end_comment

begin_comment
comment|// when handling ELF relocations.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GOLD_RELOC_TYPES_H
end_ifndef

begin_define
define|#
directive|define
name|GOLD_RELOC_TYPES_H
end_define

begin_include
include|#
directive|include
file|"elfcpp.h"
end_include

begin_decl_stmt
name|namespace
name|gold
block|{
comment|// Pick the ELF relocation accessor class and the size based on
comment|// SH_TYPE, which is either elfcpp::SHT_REL or elfcpp::SHT_RELA.
name|template
operator|<
name|int
name|sh_type
operator|,
name|int
name|size
operator|,
name|bool
name|big_endian
operator|>
expr|struct
name|Reloc_types
expr_stmt|;
name|template
operator|<
name|int
name|size
operator|,
name|bool
name|big_endian
operator|>
expr|struct
name|Reloc_types
operator|<
name|elfcpp
operator|::
name|SHT_REL
operator|,
name|size
operator|,
name|big_endian
operator|>
block|{
typedef|typedef
name|typename
name|elfcpp
operator|::
name|Rel
operator|<
name|size
operator|,
name|big_endian
operator|>
name|Reloc
expr_stmt|;
specifier|static
specifier|const
name|int
name|reloc_size
operator|=
name|elfcpp
operator|::
name|Elf_sizes
operator|<
name|size
operator|>
operator|::
name|rel_size
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|int
name|size
operator|,
name|bool
name|big_endian
operator|>
expr|struct
name|Reloc_types
operator|<
name|elfcpp
operator|::
name|SHT_RELA
operator|,
name|size
operator|,
name|big_endian
operator|>
block|{
typedef|typedef
name|typename
name|elfcpp
operator|::
name|Rela
operator|<
name|size
operator|,
name|big_endian
operator|>
name|Reloc
expr_stmt|;
specifier|static
specifier|const
name|int
name|reloc_size
operator|=
name|elfcpp
operator|::
name|Elf_sizes
operator|<
name|size
operator|>
operator|::
name|rela_size
expr_stmt|;
end_expr_stmt

begin_comment
unit|};  };
comment|// End namespace gold.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !defined(GOLD_RELOC_TYPE_SH)
end_comment

end_unit

