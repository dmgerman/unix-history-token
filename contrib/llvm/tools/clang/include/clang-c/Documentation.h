begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*==-- clang-c/Documentation.h - Utilities for comment processing -*- C -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This header provides a supplementary interface for inspecting              *| |* documentation comments.                                                    *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_C_DOCUMENTATION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_C_DOCUMENTATION_H
end_define

begin_include
include|#
directive|include
file|"clang-c/Index.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/**  * \defgroup CINDEX_COMMENT Comment introspection  *  * The routines in this group provide access to information in documentation  * comments. These facilities are distinct from the core and may be subject to  * their own schedule of stability and deprecation.  *  * @{  */
comment|/**  * \brief A parsed comment.  */
typedef|typedef
struct|struct
block|{
specifier|const
name|void
modifier|*
name|ASTNode
decl_stmt|;
name|CXTranslationUnit
name|TranslationUnit
decl_stmt|;
block|}
name|CXComment
typedef|;
comment|/**  * \brief Given a cursor that represents a documentable entity (e.g.,  * declaration), return the associated parsed comment as a  * \c CXComment_FullComment AST node.  */
name|CINDEX_LINKAGE
name|CXComment
name|clang_Cursor_getParsedComment
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * \brief Describes the type of the comment AST node (\c CXComment).  A comment  * node can be considered block content (e. g., paragraph), inline content  * (plain text) or neither (the root AST node).  */
enum|enum
name|CXCommentKind
block|{
comment|/**    * \brief Null comment.  No AST node is constructed at the requested location    * because there is no text or a syntax error.    */
name|CXComment_Null
init|=
literal|0
block|,
comment|/**    * \brief Plain text.  Inline content.    */
name|CXComment_Text
init|=
literal|1
block|,
comment|/**    * \brief A command with word-like arguments that is considered inline content.    *    * For example: \\c command.    */
name|CXComment_InlineCommand
init|=
literal|2
block|,
comment|/**    * \brief HTML start tag with attributes (name-value pairs).  Considered    * inline content.    *    * For example:    * \verbatim    *<br><br /><a href="http://example.org/">    * \endverbatim    */
name|CXComment_HTMLStartTag
init|=
literal|3
block|,
comment|/**    * \brief HTML end tag.  Considered inline content.    *    * For example:    * \verbatim    *</a>    * \endverbatim    */
name|CXComment_HTMLEndTag
init|=
literal|4
block|,
comment|/**    * \brief A paragraph, contains inline comment.  The paragraph itself is    * block content.    */
name|CXComment_Paragraph
init|=
literal|5
block|,
comment|/**    * \brief A command that has zero or more word-like arguments (number of    * word-like arguments depends on command name) and a paragraph as an    * argument.  Block command is block content.    *    * Paragraph argument is also a child of the block command.    *    * For example: \\brief has 0 word-like arguments and a paragraph argument.    *    * AST nodes of special kinds that parser knows about (e. g., \\param    * command) have their own node kinds.    */
name|CXComment_BlockCommand
init|=
literal|6
block|,
comment|/**    * \brief A \\param or \\arg command that describes the function parameter    * (name, passing direction, description).    *    * For example: \\param [in] ParamName description.    */
name|CXComment_ParamCommand
init|=
literal|7
block|,
comment|/**    * \brief A \\tparam command that describes a template parameter (name and    * description).    *    * For example: \\tparam T description.    */
name|CXComment_TParamCommand
init|=
literal|8
block|,
comment|/**    * \brief A verbatim block command (e. g., preformatted code).  Verbatim    * block has an opening and a closing command and contains multiple lines of    * text (\c CXComment_VerbatimBlockLine child nodes).    *    * For example:    * \\verbatim    * aaa    * \\endverbatim    */
name|CXComment_VerbatimBlockCommand
init|=
literal|9
block|,
comment|/**    * \brief A line of text that is contained within a    * CXComment_VerbatimBlockCommand node.    */
name|CXComment_VerbatimBlockLine
init|=
literal|10
block|,
comment|/**    * \brief A verbatim line command.  Verbatim line has an opening command,    * a single line of text (up to the newline after the opening command) and    * has no closing command.    */
name|CXComment_VerbatimLine
init|=
literal|11
block|,
comment|/**    * \brief A full comment attached to a declaration, contains block content.    */
name|CXComment_FullComment
init|=
literal|12
block|}
enum|;
comment|/**  * \brief The most appropriate rendering mode for an inline command, chosen on  * command semantics in Doxygen.  */
enum|enum
name|CXCommentInlineCommandRenderKind
block|{
comment|/**    * \brief Command argument should be rendered in a normal font.    */
name|CXCommentInlineCommandRenderKind_Normal
block|,
comment|/**    * \brief Command argument should be rendered in a bold font.    */
name|CXCommentInlineCommandRenderKind_Bold
block|,
comment|/**    * \brief Command argument should be rendered in a monospaced font.    */
name|CXCommentInlineCommandRenderKind_Monospaced
block|,
comment|/**    * \brief Command argument should be rendered emphasized (typically italic    * font).    */
name|CXCommentInlineCommandRenderKind_Emphasized
block|}
enum|;
comment|/**  * \brief Describes parameter passing direction for \\param or \\arg command.  */
enum|enum
name|CXCommentParamPassDirection
block|{
comment|/**    * \brief The parameter is an input parameter.    */
name|CXCommentParamPassDirection_In
block|,
comment|/**    * \brief The parameter is an output parameter.    */
name|CXCommentParamPassDirection_Out
block|,
comment|/**    * \brief The parameter is an input and output parameter.    */
name|CXCommentParamPassDirection_InOut
block|}
enum|;
comment|/**  * \param Comment AST node of any kind.  *  * \returns the type of the AST node.  */
name|CINDEX_LINKAGE
name|enum
name|CXCommentKind
name|clang_Comment_getKind
parameter_list|(
name|CXComment
name|Comment
parameter_list|)
function_decl|;
comment|/**  * \param Comment AST node of any kind.  *  * \returns number of children of the AST node.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_Comment_getNumChildren
parameter_list|(
name|CXComment
name|Comment
parameter_list|)
function_decl|;
comment|/**  * \param Comment AST node of any kind.  *  * \param ChildIdx child index (zero-based).  *  * \returns the specified child of the AST node.  */
name|CINDEX_LINKAGE
name|CXComment
name|clang_Comment_getChild
parameter_list|(
name|CXComment
name|Comment
parameter_list|,
name|unsigned
name|ChildIdx
parameter_list|)
function_decl|;
comment|/**  * \brief A \c CXComment_Paragraph node is considered whitespace if it contains  * only \c CXComment_Text nodes that are empty or whitespace.  *  * Other AST nodes (except \c CXComment_Paragraph and \c CXComment_Text) are  * never considered whitespace.  *  * \returns non-zero if \c Comment is whitespace.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_Comment_isWhitespace
parameter_list|(
name|CXComment
name|Comment
parameter_list|)
function_decl|;
comment|/**  * \returns non-zero if \c Comment is inline content and has a newline  * immediately following it in the comment text.  Newlines between paragraphs  * do not count.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_InlineContentComment_hasTrailingNewline
parameter_list|(
name|CXComment
name|Comment
parameter_list|)
function_decl|;
comment|/**  * \param Comment a \c CXComment_Text AST node.  *  * \returns text contained in the AST node.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_TextComment_getText
parameter_list|(
name|CXComment
name|Comment
parameter_list|)
function_decl|;
comment|/**  * \param Comment a \c CXComment_InlineCommand AST node.  *  * \returns name of the inline command.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_InlineCommandComment_getCommandName
parameter_list|(
name|CXComment
name|Comment
parameter_list|)
function_decl|;
comment|/**  * \param Comment a \c CXComment_InlineCommand AST node.  *  * \returns the most appropriate rendering mode, chosen on command  * semantics in Doxygen.  */
name|CINDEX_LINKAGE
name|enum
name|CXCommentInlineCommandRenderKind
name|clang_InlineCommandComment_getRenderKind
parameter_list|(
name|CXComment
name|Comment
parameter_list|)
function_decl|;
comment|/**  * \param Comment a \c CXComment_InlineCommand AST node.  *  * \returns number of command arguments.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_InlineCommandComment_getNumArgs
parameter_list|(
name|CXComment
name|Comment
parameter_list|)
function_decl|;
comment|/**  * \param Comment a \c CXComment_InlineCommand AST node.  *  * \param ArgIdx argument index (zero-based).  *  * \returns text of the specified argument.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_InlineCommandComment_getArgText
parameter_list|(
name|CXComment
name|Comment
parameter_list|,
name|unsigned
name|ArgIdx
parameter_list|)
function_decl|;
comment|/**  * \param Comment a \c CXComment_HTMLStartTag or \c CXComment_HTMLEndTag AST  * node.  *  * \returns HTML tag name.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_HTMLTagComment_getTagName
parameter_list|(
name|CXComment
name|Comment
parameter_list|)
function_decl|;
comment|/**  * \param Comment a \c CXComment_HTMLStartTag AST node.  *  * \returns non-zero if tag is self-closing (for example,&lt;br /&gt;).  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_HTMLStartTagComment_isSelfClosing
parameter_list|(
name|CXComment
name|Comment
parameter_list|)
function_decl|;
comment|/**  * \param Comment a \c CXComment_HTMLStartTag AST node.  *  * \returns number of attributes (name-value pairs) attached to the start tag.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_HTMLStartTag_getNumAttrs
parameter_list|(
name|CXComment
name|Comment
parameter_list|)
function_decl|;
comment|/**  * \param Comment a \c CXComment_HTMLStartTag AST node.  *  * \param AttrIdx attribute index (zero-based).  *  * \returns name of the specified attribute.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_HTMLStartTag_getAttrName
parameter_list|(
name|CXComment
name|Comment
parameter_list|,
name|unsigned
name|AttrIdx
parameter_list|)
function_decl|;
comment|/**  * \param Comment a \c CXComment_HTMLStartTag AST node.  *  * \param AttrIdx attribute index (zero-based).  *  * \returns value of the specified attribute.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_HTMLStartTag_getAttrValue
parameter_list|(
name|CXComment
name|Comment
parameter_list|,
name|unsigned
name|AttrIdx
parameter_list|)
function_decl|;
comment|/**  * \param Comment a \c CXComment_BlockCommand AST node.  *  * \returns name of the block command.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_BlockCommandComment_getCommandName
parameter_list|(
name|CXComment
name|Comment
parameter_list|)
function_decl|;
comment|/**  * \param Comment a \c CXComment_BlockCommand AST node.  *  * \returns number of word-like arguments.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_BlockCommandComment_getNumArgs
parameter_list|(
name|CXComment
name|Comment
parameter_list|)
function_decl|;
comment|/**  * \param Comment a \c CXComment_BlockCommand AST node.  *  * \param ArgIdx argument index (zero-based).  *  * \returns text of the specified word-like argument.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_BlockCommandComment_getArgText
parameter_list|(
name|CXComment
name|Comment
parameter_list|,
name|unsigned
name|ArgIdx
parameter_list|)
function_decl|;
comment|/**  * \param Comment a \c CXComment_BlockCommand or  * \c CXComment_VerbatimBlockCommand AST node.  *  * \returns paragraph argument of the block command.  */
name|CINDEX_LINKAGE
name|CXComment
name|clang_BlockCommandComment_getParagraph
parameter_list|(
name|CXComment
name|Comment
parameter_list|)
function_decl|;
comment|/**  * \param Comment a \c CXComment_ParamCommand AST node.  *  * \returns parameter name.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_ParamCommandComment_getParamName
parameter_list|(
name|CXComment
name|Comment
parameter_list|)
function_decl|;
comment|/**  * \param Comment a \c CXComment_ParamCommand AST node.  *  * \returns non-zero if the parameter that this AST node represents was found  * in the function prototype and \c clang_ParamCommandComment_getParamIndex  * function will return a meaningful value.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_ParamCommandComment_isParamIndexValid
parameter_list|(
name|CXComment
name|Comment
parameter_list|)
function_decl|;
comment|/**  * \param Comment a \c CXComment_ParamCommand AST node.  *  * \returns zero-based parameter index in function prototype.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_ParamCommandComment_getParamIndex
parameter_list|(
name|CXComment
name|Comment
parameter_list|)
function_decl|;
comment|/**  * \param Comment a \c CXComment_ParamCommand AST node.  *  * \returns non-zero if parameter passing direction was specified explicitly in  * the comment.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_ParamCommandComment_isDirectionExplicit
parameter_list|(
name|CXComment
name|Comment
parameter_list|)
function_decl|;
comment|/**  * \param Comment a \c CXComment_ParamCommand AST node.  *  * \returns parameter passing direction.  */
name|CINDEX_LINKAGE
name|enum
name|CXCommentParamPassDirection
name|clang_ParamCommandComment_getDirection
parameter_list|(
name|CXComment
name|Comment
parameter_list|)
function_decl|;
comment|/**  * \param Comment a \c CXComment_TParamCommand AST node.  *  * \returns template parameter name.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_TParamCommandComment_getParamName
parameter_list|(
name|CXComment
name|Comment
parameter_list|)
function_decl|;
comment|/**  * \param Comment a \c CXComment_TParamCommand AST node.  *  * \returns non-zero if the parameter that this AST node represents was found  * in the template parameter list and  * \c clang_TParamCommandComment_getDepth and  * \c clang_TParamCommandComment_getIndex functions will return a meaningful  * value.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_TParamCommandComment_isParamPositionValid
parameter_list|(
name|CXComment
name|Comment
parameter_list|)
function_decl|;
comment|/**  * \param Comment a \c CXComment_TParamCommand AST node.  *  * \returns zero-based nesting depth of this parameter in the template parameter list.  *  * For example,  * \verbatim  *     template<typename C, template<typename T> class TT>  *     void test(TT<int> aaa);  * \endverbatim  * for C and TT nesting depth is 0,  * for T nesting depth is 1.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_TParamCommandComment_getDepth
parameter_list|(
name|CXComment
name|Comment
parameter_list|)
function_decl|;
comment|/**  * \param Comment a \c CXComment_TParamCommand AST node.  *  * \returns zero-based parameter index in the template parameter list at a  * given nesting depth.  *  * For example,  * \verbatim  *     template<typename C, template<typename T> class TT>  *     void test(TT<int> aaa);  * \endverbatim  * for C and TT nesting depth is 0, so we can ask for index at depth 0:  * at depth 0 C's index is 0, TT's index is 1.  *  * For T nesting depth is 1, so we can ask for index at depth 0 and 1:  * at depth 0 T's index is 1 (same as TT's),  * at depth 1 T's index is 0.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_TParamCommandComment_getIndex
parameter_list|(
name|CXComment
name|Comment
parameter_list|,
name|unsigned
name|Depth
parameter_list|)
function_decl|;
comment|/**  * \param Comment a \c CXComment_VerbatimBlockLine AST node.  *  * \returns text contained in the AST node.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_VerbatimBlockLineComment_getText
parameter_list|(
name|CXComment
name|Comment
parameter_list|)
function_decl|;
comment|/**  * \param Comment a \c CXComment_VerbatimLine AST node.  *  * \returns text contained in the AST node.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_VerbatimLineComment_getText
parameter_list|(
name|CXComment
name|Comment
parameter_list|)
function_decl|;
comment|/**  * \brief Convert an HTML tag AST node to string.  *  * \param Comment a \c CXComment_HTMLStartTag or \c CXComment_HTMLEndTag AST  * node.  *  * \returns string containing an HTML tag.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_HTMLTagComment_getAsString
parameter_list|(
name|CXComment
name|Comment
parameter_list|)
function_decl|;
comment|/**  * \brief Convert a given full parsed comment to an HTML fragment.  *  * Specific details of HTML layout are subject to change.  Don't try to parse  * this HTML back into an AST, use other APIs instead.  *  * Currently the following CSS classes are used:  * \li "para-brief" for \\brief paragraph and equivalent commands;  * \li "para-returns" for \\returns paragraph and equivalent commands;  * \li "word-returns" for the "Returns" word in \\returns paragraph.  *  * Function argument documentation is rendered as a \<dl\> list with arguments  * sorted in function prototype order.  CSS classes used:  * \li "param-name-index-NUMBER" for parameter name (\<dt\>);  * \li "param-descr-index-NUMBER" for parameter description (\<dd\>);  * \li "param-name-index-invalid" and "param-descr-index-invalid" are used if  * parameter index is invalid.  *  * Template parameter documentation is rendered as a \<dl\> list with  * parameters sorted in template parameter list order.  CSS classes used:  * \li "tparam-name-index-NUMBER" for parameter name (\<dt\>);  * \li "tparam-descr-index-NUMBER" for parameter description (\<dd\>);  * \li "tparam-name-index-other" and "tparam-descr-index-other" are used for  * names inside template template parameters;  * \li "tparam-name-index-invalid" and "tparam-descr-index-invalid" are used if  * parameter position is invalid.  *  * \param Comment a \c CXComment_FullComment AST node.  *  * \returns string containing an HTML fragment.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_FullComment_getAsHTML
parameter_list|(
name|CXComment
name|Comment
parameter_list|)
function_decl|;
comment|/**  * \brief Convert a given full parsed comment to an XML document.  *  * A Relax NG schema for the XML can be found in comment-xml-schema.rng file  * inside clang source tree.  *  * \param Comment a \c CXComment_FullComment AST node.  *  * \returns string containing an XML document.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_FullComment_getAsXML
parameter_list|(
name|CXComment
name|Comment
parameter_list|)
function_decl|;
comment|/**  * @}  */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CLANG_C_DOCUMENTATION_H */
end_comment

end_unit

