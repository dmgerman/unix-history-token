begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_comment
comment|/**  * @file apr_xml.h  * @brief APR-UTIL XML Library  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_XML_H
end_ifndef

begin_define
define|#
directive|define
name|APR_XML_H
end_define

begin_comment
comment|/**  * @defgroup APR_Util_XML XML   * @ingroup APR_Util  * @{  */
end_comment

begin_include
include|#
directive|include
file|"apr_pools.h"
end_include

begin_include
include|#
directive|include
file|"apr_tables.h"
end_include

begin_include
include|#
directive|include
file|"apr_file_io.h"
end_include

begin_include
include|#
directive|include
file|"apu.h"
end_include

begin_if
if|#
directive|if
name|APR_CHARSET_EBCDIC
end_if

begin_include
include|#
directive|include
file|"apr_xlate.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

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
comment|/**  * @package Apache XML library  */
comment|/* -------------------------------------------------------------------- */
comment|/* ### these will need to move at some point to a more logical spot */
comment|/** @see apr_text */
typedef|typedef
name|struct
name|apr_text
name|apr_text
typedef|;
comment|/** Structure to keep a linked list of pieces of text */
struct|struct
name|apr_text
block|{
comment|/** The current piece of text */
specifier|const
name|char
modifier|*
name|text
decl_stmt|;
comment|/** a pointer to the next piece of text */
name|struct
name|apr_text
modifier|*
name|next
decl_stmt|;
block|}
struct|;
comment|/** @see apr_text_header */
typedef|typedef
name|struct
name|apr_text_header
name|apr_text_header
typedef|;
comment|/** A list of pieces of text */
struct|struct
name|apr_text_header
block|{
comment|/** The first piece of text in the list */
name|apr_text
modifier|*
name|first
decl_stmt|;
comment|/** The last piece of text in the list */
name|apr_text
modifier|*
name|last
decl_stmt|;
block|}
struct|;
comment|/**  * Append a piece of text to the end of a list  * @param p The pool to allocate out of  * @param hdr The text header to append to  * @param text The new text to append  */
name|APU_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_text_append
argument_list|(
name|apr_pool_t
operator|*
name|p
argument_list|,
name|apr_text_header
operator|*
name|hdr
argument_list|,
specifier|const
name|char
operator|*
name|text
argument_list|)
expr_stmt|;
comment|/* -------------------------------------------------------------------- ** ** XML PARSING */
comment|/* ** Qualified namespace values ** ** APR_XML_NS_DAV_ID **    We always insert the "DAV:" namespace URI at the head of the **    namespace array. This means that it will always be at ID==0, **    making it much easier to test for. ** ** APR_XML_NS_NONE **    This special ID is used for two situations: ** **    1) The namespace prefix begins with "xml" (and we do not know **       what it means). Namespace prefixes with "xml" (any case) as **       their first three characters are reserved by the XML Namespaces **       specification for future use. mod_dav will pass these through **       unchanged. When this identifier is used, the prefix is LEFT in **       the element/attribute name. Downstream processing should not **       prepend another prefix. ** **    2) The element/attribute does not have a namespace. ** **       a) No prefix was used, and a default namespace has not been **          defined. **       b) No prefix was used, and the default namespace was specified **          to mean "no namespace". This is done with a namespace **          declaration of:  xmlns="" **          (this declaration is typically used to override a previous **          specification for the default namespace) ** **       In these cases, we need to record that the elem/attr has no **       namespace so that we will not attempt to prepend a prefix. **       All namespaces that are used will have a prefix assigned to **       them -- mod_dav will never set or use the default namespace **       when generating XML. This means that "no prefix" will always **       mean "no namespace". ** **    In both cases, the XML generation will avoid prepending a prefix. **    For the first case, this means the original prefix/name will be **    inserted into the output stream. For the latter case, it means **    the name will have no prefix, and since we never define a default **    namespace, this means it will have no namespace. ** ** Note: currently, mod_dav understands the "xmlns" prefix and the **     "xml:lang" attribute. These are handled specially (they aren't **     left within the XML tree), so the APR_XML_NS_NONE value won't ever **     really apply to these values. */
define|#
directive|define
name|APR_XML_NS_DAV_ID
value|0
comment|/**< namespace ID for "DAV:" */
define|#
directive|define
name|APR_XML_NS_NONE
value|-10
comment|/**< no namespace for this elem/attr */
define|#
directive|define
name|APR_XML_NS_ERROR_BASE
value|-100
comment|/**< used only during processing */
comment|/** Is this namespace an error? */
define|#
directive|define
name|APR_XML_NS_IS_ERROR
parameter_list|(
name|e
parameter_list|)
value|((e)<= APR_XML_NS_ERROR_BASE)
comment|/** @see apr_xml_attr */
typedef|typedef
name|struct
name|apr_xml_attr
name|apr_xml_attr
typedef|;
comment|/** @see apr_xml_elem */
typedef|typedef
name|struct
name|apr_xml_elem
name|apr_xml_elem
typedef|;
comment|/** @see apr_xml_doc */
typedef|typedef
name|struct
name|apr_xml_doc
name|apr_xml_doc
typedef|;
comment|/** apr_xml_attr: holds a parsed XML attribute */
struct|struct
name|apr_xml_attr
block|{
comment|/** attribute name */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/** index into namespace array */
name|int
name|ns
decl_stmt|;
comment|/** attribute value */
specifier|const
name|char
modifier|*
name|value
decl_stmt|;
comment|/** next attribute */
name|struct
name|apr_xml_attr
modifier|*
name|next
decl_stmt|;
block|}
struct|;
comment|/** apr_xml_elem: holds a parsed XML element */
struct|struct
name|apr_xml_elem
block|{
comment|/** element name */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/** index into namespace array */
name|int
name|ns
decl_stmt|;
comment|/** xml:lang for attrs/contents */
specifier|const
name|char
modifier|*
name|lang
decl_stmt|;
comment|/** cdata right after start tag */
name|apr_text_header
name|first_cdata
decl_stmt|;
comment|/** cdata after MY end tag */
name|apr_text_header
name|following_cdata
decl_stmt|;
comment|/** parent element */
name|struct
name|apr_xml_elem
modifier|*
name|parent
decl_stmt|;
comment|/** next (sibling) element */
name|struct
name|apr_xml_elem
modifier|*
name|next
decl_stmt|;
comment|/** first child element */
name|struct
name|apr_xml_elem
modifier|*
name|first_child
decl_stmt|;
comment|/** first attribute */
name|struct
name|apr_xml_attr
modifier|*
name|attr
decl_stmt|;
comment|/* used only during parsing */
comment|/** last child element */
name|struct
name|apr_xml_elem
modifier|*
name|last_child
decl_stmt|;
comment|/** namespaces scoped by this elem */
name|struct
name|apr_xml_ns_scope
modifier|*
name|ns_scope
decl_stmt|;
comment|/* used by modules during request processing */
comment|/** Place for modules to store private data */
name|void
modifier|*
name|priv
decl_stmt|;
block|}
struct|;
comment|/** Is this XML element empty? */
define|#
directive|define
name|APR_XML_ELEM_IS_EMPTY
parameter_list|(
name|e
parameter_list|)
value|((e)->first_child == NULL&& \                                   (e)->first_cdata.first == NULL)
comment|/** apr_xml_doc: holds a parsed XML document */
struct|struct
name|apr_xml_doc
block|{
comment|/** root element */
name|apr_xml_elem
modifier|*
name|root
decl_stmt|;
comment|/** array of namespaces used */
name|apr_array_header_t
modifier|*
name|namespaces
decl_stmt|;
block|}
struct|;
comment|/** Opaque XML parser structure */
typedef|typedef
name|struct
name|apr_xml_parser
name|apr_xml_parser
typedef|;
comment|/**  * Create an XML parser  * @param pool The pool for allocating the parser and the parse results.  * @return The new parser.  */
name|APU_DECLARE
argument_list|(
argument|apr_xml_parser *
argument_list|)
name|apr_xml_parser_create
argument_list|(
name|apr_pool_t
operator|*
name|pool
argument_list|)
expr_stmt|;
comment|/**  * Parse a File, producing a xml_doc  * @param p      The pool for allocating the parse results.  * @param parser A pointer to *parser (needed so calling function can get  *               errors), will be set to NULL on successful completion.  * @param ppdoc  A pointer to *apr_xml_doc (which has the parsed results in it)  * @param xmlfd  A file to read from.  * @param buffer_length Buffer length which would be suitable   * @return Any errors found during parsing.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_xml_parse_file
argument_list|(
argument|apr_pool_t *p
argument_list|,
argument|apr_xml_parser **parser
argument_list|,
argument|apr_xml_doc **ppdoc
argument_list|,
argument|apr_file_t *xmlfd
argument_list|,
argument|apr_size_t buffer_length
argument_list|)
empty_stmt|;
comment|/**  * Feed input into the parser  * @param parser The XML parser for parsing this data.  * @param data The data to parse.  * @param len The length of the data.  * @return Any errors found during parsing.  * @remark Use apr_xml_parser_geterror() to get more error information.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_xml_parser_feed
argument_list|(
argument|apr_xml_parser *parser
argument_list|,
argument|const char *data
argument_list|,
argument|apr_size_t len
argument_list|)
empty_stmt|;
comment|/**  * Terminate the parsing and return the result  * @param parser The XML parser for parsing this data.  * @param pdoc The resulting parse information. May be NULL to simply  *             terminate the parsing without fetching the info.  * @return Any errors found during the final stage of parsing.  * @remark Use apr_xml_parser_geterror() to get more error information.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_xml_parser_done
argument_list|(
name|apr_xml_parser
operator|*
name|parser
argument_list|,
name|apr_xml_doc
operator|*
operator|*
name|pdoc
argument_list|)
expr_stmt|;
comment|/**  * Fetch additional error information from the parser.  * @param parser The XML parser to query for errors.  * @param errbuf A buffer for storing error text.  * @param errbufsize The length of the error text buffer.  * @return The error buffer  */
name|APU_DECLARE
argument_list|(
argument|char *
argument_list|)
name|apr_xml_parser_geterror
argument_list|(
argument|apr_xml_parser *parser
argument_list|,
argument|char *errbuf
argument_list|,
argument|apr_size_t errbufsize
argument_list|)
empty_stmt|;
comment|/**  * Converts an XML element tree to flat text   * @param p The pool to allocate out of  * @param elem The XML element to convert  * @param style How to covert the XML.  One of:  *<PRE>  *     APR_XML_X2T_FULL                start tag, contents, end tag   *     APR_XML_X2T_INNER               contents only   *     APR_XML_X2T_LANG_INNER          xml:lang + inner contents   *     APR_XML_X2T_FULL_NS_LANG        FULL + ns defns + xml:lang   *</PRE>  * @param namespaces The namespace of the current XML element  * @param ns_map Namespace mapping  * @param pbuf Buffer to put the converted text into  * @param psize Size of the converted text  */
name|APU_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_xml_to_text
argument_list|(
argument|apr_pool_t *p
argument_list|,
argument|const apr_xml_elem *elem
argument_list|,
argument|int style
argument_list|,
argument|apr_array_header_t *namespaces
argument_list|,
argument|int *ns_map
argument_list|,
argument|const char **pbuf
argument_list|,
argument|apr_size_t *psize
argument_list|)
empty_stmt|;
comment|/* style argument values: */
define|#
directive|define
name|APR_XML_X2T_FULL
value|0
comment|/**< start tag, contents, end tag */
define|#
directive|define
name|APR_XML_X2T_INNER
value|1
comment|/**< contents only */
define|#
directive|define
name|APR_XML_X2T_LANG_INNER
value|2
comment|/**< xml:lang + inner contents */
define|#
directive|define
name|APR_XML_X2T_FULL_NS_LANG
value|3
comment|/**< FULL + ns defns + xml:lang */
comment|/**  * empty XML element  * @param p The pool to allocate out of  * @param elem The XML element to empty  * @return the string that was stored in the XML element  */
name|APU_DECLARE
argument_list|(
argument|const char *
argument_list|)
name|apr_xml_empty_elem
argument_list|(
name|apr_pool_t
operator|*
name|p
argument_list|,
specifier|const
name|apr_xml_elem
operator|*
name|elem
argument_list|)
expr_stmt|;
comment|/**  * quote an XML string  * Replace '\<', '\>', and '\&' with '\&lt;', '\&gt;', and '\&amp;'.  * @param p The pool to allocate out of  * @param s The string to quote  * @param quotes If quotes is true, then replace '&quot;' with '\&quot;'.  * @return The quoted string  * @note If the string does not contain special characters, it is not  * duplicated into the pool and the original string is returned.  */
name|APU_DECLARE
argument_list|(
argument|const char *
argument_list|)
name|apr_xml_quote_string
argument_list|(
argument|apr_pool_t *p
argument_list|,
argument|const char *s
argument_list|,
argument|int quotes
argument_list|)
empty_stmt|;
comment|/**  * Quote an XML element  * @param p The pool to allocate out of  * @param elem The element to quote  */
name|APU_DECLARE
argument_list|(
argument|void
argument_list|)
name|apr_xml_quote_elem
argument_list|(
name|apr_pool_t
operator|*
name|p
argument_list|,
name|apr_xml_elem
operator|*
name|elem
argument_list|)
expr_stmt|;
comment|/* manage an array of unique URIs: apr_xml_insert_uri() and APR_XML_URI_ITEM() */
comment|/**  * return the URI's (existing) index, or insert it and return a new index   * @param uri_array array to insert into  * @param uri The uri to insert  * @return int The uri's index  */
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_xml_insert_uri
argument_list|(
name|apr_array_header_t
operator|*
name|uri_array
argument_list|,
specifier|const
name|char
operator|*
name|uri
argument_list|)
expr_stmt|;
comment|/** Get the URI item for this XML element */
define|#
directive|define
name|APR_XML_GET_URI_ITEM
parameter_list|(
name|ary
parameter_list|,
name|i
parameter_list|)
value|(((const char * const *)(ary)->elts)[i])
if|#
directive|if
name|APR_CHARSET_EBCDIC
comment|/**  * Convert parsed tree in EBCDIC   * @param p The pool to allocate out of  * @param pdoc The apr_xml_doc to convert.  * @param xlate The translation handle to use.  * @return Any errors found during conversion.  */
name|APU_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_xml_parser_convert_doc
argument_list|(
name|apr_pool_t
operator|*
name|p
argument_list|,
name|apr_xml_doc
operator|*
name|pdoc
argument_list|,
name|apr_xlate_t
operator|*
name|convset
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/** @} */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APR_XML_H */
end_comment

end_unit

