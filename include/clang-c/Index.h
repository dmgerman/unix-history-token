begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- clang-c/Index.h - Indexing Public C Interface -------------*- C -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This header provides a public inferface to a Clang library for extracting  *| |* high-level symbol information from source files without exposing the full  *| |* Clang C++ API.                                                             *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CLANG_C_INDEX_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_C_INDEX_H
end_define

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
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
comment|/* MSVC DLL import/export. */
ifdef|#
directive|ifdef
name|_MSC_VER
ifdef|#
directive|ifdef
name|_CINDEX_LIB_
define|#
directive|define
name|CINDEX_LINKAGE
value|__declspec(dllexport)
else|#
directive|else
define|#
directive|define
name|CINDEX_LINKAGE
value|__declspec(dllimport)
endif|#
directive|endif
else|#
directive|else
define|#
directive|define
name|CINDEX_LINKAGE
endif|#
directive|endif
comment|/** \defgroup CINDEX libclang: C Interface to Clang  *  * The C Interface to Clang provides a relatively small API that exposes  * facilities for parsing source code into an abstract syntax tree (AST),  * loading already-parsed ASTs, traversing the AST, associating  * physical source locations with elements within the AST, and other  * facilities that support Clang-based development tools.  *  * This C interface to Clang will never provide all of the information  * representation stored in Clang's C++ AST, nor should it: the intent is to  * maintain an API that is relatively stable from one release to the next,  * providing only the basic functionality needed to support development tools.  *  * To avoid namespace pollution, data types are prefixed with "CX" and  * functions are prefixed with "clang_".  *  * @{  */
comment|/**  * \brief An "index" that consists of a set of translation units that would  * typically be linked together into an executable or library.  */
typedef|typedef
name|void
modifier|*
name|CXIndex
typedef|;
comment|/**  * \brief A single translation unit, which resides in an index.  */
typedef|typedef
name|struct
name|CXTranslationUnitImpl
modifier|*
name|CXTranslationUnit
typedef|;
comment|/**  * \brief Opaque pointer representing client data that will be passed through  * to various callbacks and visitors.  */
typedef|typedef
name|void
modifier|*
name|CXClientData
typedef|;
comment|/**  * \brief Provides the contents of a file that has not yet been saved to disk.  *  * Each CXUnsavedFile instance provides the name of a file on the  * system along with the current contents of that file that have not  * yet been saved to disk.  */
struct|struct
name|CXUnsavedFile
block|{
comment|/**    * \brief The file whose contents have not yet been saved.    *    * This file must already exist in the file system.    */
specifier|const
name|char
modifier|*
name|Filename
decl_stmt|;
comment|/**    * \brief A buffer containing the unsaved contents of this file.    */
specifier|const
name|char
modifier|*
name|Contents
decl_stmt|;
comment|/**    * \brief The length of the unsaved contents of this buffer.    */
name|unsigned
name|long
name|Length
decl_stmt|;
block|}
struct|;
comment|/**  * \brief Describes the availability of a particular entity, which indicates  * whether the use of this entity will result in a warning or error due to  * it being deprecated or unavailable.  */
enum|enum
name|CXAvailabilityKind
block|{
comment|/**    * \brief The entity is available.    */
name|CXAvailability_Available
block|,
comment|/**    * \brief The entity is available, but has been deprecated (and its use is    * not recommended).    */
name|CXAvailability_Deprecated
block|,
comment|/**    * \brief The entity is not available; any use of it will be an error.    */
name|CXAvailability_NotAvailable
block|}
enum|;
comment|/**  * \defgroup CINDEX_STRING String manipulation routines  *  * @{  */
comment|/**  * \brief A character string.  *  * The \c CXString type is used to return strings from the interface when  * the ownership of that string might different from one call to the next.  * Use \c clang_getCString() to retrieve the string data and, once finished  * with the string data, call \c clang_disposeString() to free the string.  */
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|data
decl_stmt|;
name|unsigned
name|private_flags
decl_stmt|;
block|}
name|CXString
typedef|;
comment|/**  * \brief Retrieve the character data associated with the given string.  */
name|CINDEX_LINKAGE
specifier|const
name|char
modifier|*
name|clang_getCString
parameter_list|(
name|CXString
name|string
parameter_list|)
function_decl|;
comment|/**  * \brief Free the given string,  */
name|CINDEX_LINKAGE
name|void
name|clang_disposeString
parameter_list|(
name|CXString
name|string
parameter_list|)
function_decl|;
comment|/**  * @}  */
comment|/**  * \brief clang_createIndex() provides a shared context for creating  * translation units. It provides two options:  *  * - excludeDeclarationsFromPCH: When non-zero, allows enumeration of "local"  * declarations (when loading any new translation units). A "local" declaration  * is one that belongs in the translation unit itself and not in a precompiled  * header that was used by the translation unit. If zero, all declarations  * will be enumerated.  *  * Here is an example:  *  *   // excludeDeclsFromPCH = 1, displayDiagnostics=1  *   Idx = clang_createIndex(1, 1);  *  *   // IndexTest.pch was produced with the following command:  *   // "clang -x c IndexTest.h -emit-ast -o IndexTest.pch"  *   TU = clang_createTranslationUnit(Idx, "IndexTest.pch");  *  *   // This will load all the symbols from 'IndexTest.pch'  *   clang_visitChildren(clang_getTranslationUnitCursor(TU),  *                       TranslationUnitVisitor, 0);  *   clang_disposeTranslationUnit(TU);  *  *   // This will load all the symbols from 'IndexTest.c', excluding symbols  *   // from 'IndexTest.pch'.  *   char *args[] = { "-Xclang", "-include-pch=IndexTest.pch" };  *   TU = clang_createTranslationUnitFromSourceFile(Idx, "IndexTest.c", 2, args,  *                                                  0, 0);  *   clang_visitChildren(clang_getTranslationUnitCursor(TU),  *                       TranslationUnitVisitor, 0);  *   clang_disposeTranslationUnit(TU);  *  * This process of creating the 'pch', loading it separately, and using it (via  * -include-pch) allows 'excludeDeclsFromPCH' to remove redundant callbacks  * (which gives the indexer the same performance benefit as the compiler).  */
name|CINDEX_LINKAGE
name|CXIndex
name|clang_createIndex
parameter_list|(
name|int
name|excludeDeclarationsFromPCH
parameter_list|,
name|int
name|displayDiagnostics
parameter_list|)
function_decl|;
comment|/**  * \brief Destroy the given index.  *  * The index must not be destroyed until all of the translation units created  * within that index have been destroyed.  */
name|CINDEX_LINKAGE
name|void
name|clang_disposeIndex
parameter_list|(
name|CXIndex
name|index
parameter_list|)
function_decl|;
comment|/**  * \defgroup CINDEX_FILES File manipulation routines  *  * @{  */
comment|/**  * \brief A particular source file that is part of a translation unit.  */
typedef|typedef
name|void
modifier|*
name|CXFile
typedef|;
comment|/**  * \brief Retrieve the complete file and path name of the given file.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_getFileName
parameter_list|(
name|CXFile
name|SFile
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the last modification time of the given file.  */
name|CINDEX_LINKAGE
name|time_t
name|clang_getFileTime
parameter_list|(
name|CXFile
name|SFile
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve a file handle within the given translation unit.  *  * \param tu the translation unit  *  * \param file_name the name of the file.  *  * \returns the file handle for the named file in the translation unit \p tu,  * or a NULL file handle if the file was not a part of this translation unit.  */
name|CINDEX_LINKAGE
name|CXFile
name|clang_getFile
parameter_list|(
name|CXTranslationUnit
name|tu
parameter_list|,
specifier|const
name|char
modifier|*
name|file_name
parameter_list|)
function_decl|;
comment|/**  * @}  */
comment|/**  * \defgroup CINDEX_LOCATIONS Physical source locations  *  * Clang represents physical source locations in its abstract syntax tree in  * great detail, with file, line, and column information for the majority of  * the tokens parsed in the source code. These data types and functions are  * used to represent source location information, either for a particular  * point in the program or for a range of points in the program, and extract  * specific location information from those data types.  *  * @{  */
comment|/**  * \brief Identifies a specific source location within a translation  * unit.  *  * Use clang_getInstantiationLocation() or clang_getSpellingLocation()  * to map a source location to a particular file, line, and column.  */
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|ptr_data
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|int_data
decl_stmt|;
block|}
name|CXSourceLocation
typedef|;
comment|/**  * \brief Identifies a half-open character range in the source code.  *  * Use clang_getRangeStart() and clang_getRangeEnd() to retrieve the  * starting and end locations from a source range, respectively.  */
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|ptr_data
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|begin_int_data
decl_stmt|;
name|unsigned
name|end_int_data
decl_stmt|;
block|}
name|CXSourceRange
typedef|;
comment|/**  * \brief Retrieve a NULL (invalid) source location.  */
name|CINDEX_LINKAGE
name|CXSourceLocation
name|clang_getNullLocation
parameter_list|()
function_decl|;
comment|/**  * \determine Determine whether two source locations, which must refer into  * the same translation unit, refer to exactly the same point in the source  * code.  *  * \returns non-zero if the source locations refer to the same location, zero  * if they refer to different locations.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_equalLocations
parameter_list|(
name|CXSourceLocation
name|loc1
parameter_list|,
name|CXSourceLocation
name|loc2
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieves the source location associated with a given file/line/column  * in a particular translation unit.  */
name|CINDEX_LINKAGE
name|CXSourceLocation
name|clang_getLocation
parameter_list|(
name|CXTranslationUnit
name|tu
parameter_list|,
name|CXFile
name|file
parameter_list|,
name|unsigned
name|line
parameter_list|,
name|unsigned
name|column
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieves the source location associated with a given character offset  * in a particular translation unit.  */
name|CINDEX_LINKAGE
name|CXSourceLocation
name|clang_getLocationForOffset
parameter_list|(
name|CXTranslationUnit
name|tu
parameter_list|,
name|CXFile
name|file
parameter_list|,
name|unsigned
name|offset
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve a NULL (invalid) source range.  */
name|CINDEX_LINKAGE
name|CXSourceRange
name|clang_getNullRange
parameter_list|()
function_decl|;
comment|/**  * \brief Retrieve a source range given the beginning and ending source  * locations.  */
name|CINDEX_LINKAGE
name|CXSourceRange
name|clang_getRange
parameter_list|(
name|CXSourceLocation
name|begin
parameter_list|,
name|CXSourceLocation
name|end
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the file, line, column, and offset represented by  * the given source location.  *  * If the location refers into a macro instantiation, retrieves the  * location of the macro instantiation.  *  * \param location the location within a source file that will be decomposed  * into its parts.  *  * \param file [out] if non-NULL, will be set to the file to which the given  * source location points.  *  * \param line [out] if non-NULL, will be set to the line to which the given  * source location points.  *  * \param column [out] if non-NULL, will be set to the column to which the given  * source location points.  *  * \param offset [out] if non-NULL, will be set to the offset into the  * buffer to which the given source location points.  */
name|CINDEX_LINKAGE
name|void
name|clang_getInstantiationLocation
parameter_list|(
name|CXSourceLocation
name|location
parameter_list|,
name|CXFile
modifier|*
name|file
parameter_list|,
name|unsigned
modifier|*
name|line
parameter_list|,
name|unsigned
modifier|*
name|column
parameter_list|,
name|unsigned
modifier|*
name|offset
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the file, line, column, and offset represented by  * the given source location.  *  * If the location refers into a macro instantiation, return where the  * location was originally spelled in the source file.  *  * \param location the location within a source file that will be decomposed  * into its parts.  *  * \param file [out] if non-NULL, will be set to the file to which the given  * source location points.  *  * \param line [out] if non-NULL, will be set to the line to which the given  * source location points.  *  * \param column [out] if non-NULL, will be set to the column to which the given  * source location points.  *  * \param offset [out] if non-NULL, will be set to the offset into the  * buffer to which the given source location points.  */
name|CINDEX_LINKAGE
name|void
name|clang_getSpellingLocation
parameter_list|(
name|CXSourceLocation
name|location
parameter_list|,
name|CXFile
modifier|*
name|file
parameter_list|,
name|unsigned
modifier|*
name|line
parameter_list|,
name|unsigned
modifier|*
name|column
parameter_list|,
name|unsigned
modifier|*
name|offset
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve a source location representing the first character within a  * source range.  */
name|CINDEX_LINKAGE
name|CXSourceLocation
name|clang_getRangeStart
parameter_list|(
name|CXSourceRange
name|range
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve a source location representing the last character within a  * source range.  */
name|CINDEX_LINKAGE
name|CXSourceLocation
name|clang_getRangeEnd
parameter_list|(
name|CXSourceRange
name|range
parameter_list|)
function_decl|;
comment|/**  * @}  */
comment|/**  * \defgroup CINDEX_DIAG Diagnostic reporting  *  * @{  */
comment|/**  * \brief Describes the severity of a particular diagnostic.  */
enum|enum
name|CXDiagnosticSeverity
block|{
comment|/**    * \brief A diagnostic that has been suppressed, e.g., by a command-line    * option.    */
name|CXDiagnostic_Ignored
init|=
literal|0
block|,
comment|/**    * \brief This diagnostic is a note that should be attached to the    * previous (non-note) diagnostic.    */
name|CXDiagnostic_Note
init|=
literal|1
block|,
comment|/**    * \brief This diagnostic indicates suspicious code that may not be    * wrong.    */
name|CXDiagnostic_Warning
init|=
literal|2
block|,
comment|/**    * \brief This diagnostic indicates that the code is ill-formed.    */
name|CXDiagnostic_Error
init|=
literal|3
block|,
comment|/**    * \brief This diagnostic indicates that the code is ill-formed such    * that future parser recovery is unlikely to produce useful    * results.    */
name|CXDiagnostic_Fatal
init|=
literal|4
block|}
enum|;
comment|/**  * \brief A single diagnostic, containing the diagnostic's severity,  * location, text, source ranges, and fix-it hints.  */
typedef|typedef
name|void
modifier|*
name|CXDiagnostic
typedef|;
comment|/**  * \brief Determine the number of diagnostics produced for the given  * translation unit.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_getNumDiagnostics
parameter_list|(
name|CXTranslationUnit
name|Unit
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve a diagnostic associated with the given translation unit.  *  * \param Unit the translation unit to query.  * \param Index the zero-based diagnostic number to retrieve.  *  * \returns the requested diagnostic. This diagnostic must be freed  * via a call to \c clang_disposeDiagnostic().  */
name|CINDEX_LINKAGE
name|CXDiagnostic
name|clang_getDiagnostic
parameter_list|(
name|CXTranslationUnit
name|Unit
parameter_list|,
name|unsigned
name|Index
parameter_list|)
function_decl|;
comment|/**  * \brief Destroy a diagnostic.  */
name|CINDEX_LINKAGE
name|void
name|clang_disposeDiagnostic
parameter_list|(
name|CXDiagnostic
name|Diagnostic
parameter_list|)
function_decl|;
comment|/**  * \brief Options to control the display of diagnostics.  *  * The values in this enum are meant to be combined to customize the  * behavior of \c clang_displayDiagnostic().  */
enum|enum
name|CXDiagnosticDisplayOptions
block|{
comment|/**    * \brief Display the source-location information where the    * diagnostic was located.    *    * When set, diagnostics will be prefixed by the file, line, and    * (optionally) column to which the diagnostic refers. For example,    *    * \code    * test.c:28: warning: extra tokens at end of #endif directive    * \endcode    *    * This option corresponds to the clang flag \c -fshow-source-location.    */
name|CXDiagnostic_DisplaySourceLocation
init|=
literal|0x01
block|,
comment|/**    * \brief If displaying the source-location information of the    * diagnostic, also include the column number.    *    * This option corresponds to the clang flag \c -fshow-column.    */
name|CXDiagnostic_DisplayColumn
init|=
literal|0x02
block|,
comment|/**    * \brief If displaying the source-location information of the    * diagnostic, also include information about source ranges in a    * machine-parsable format.    *    * This option corresponds to the clang flag    * \c -fdiagnostics-print-source-range-info.    */
name|CXDiagnostic_DisplaySourceRanges
init|=
literal|0x04
block|,
comment|/**    * \brief Display the option name associated with this diagnostic, if any.    *    * The option name displayed (e.g., -Wconversion) will be placed in brackets    * after the diagnostic text. This option corresponds to the clang flag    * \c -fdiagnostics-show-option.    */
name|CXDiagnostic_DisplayOption
init|=
literal|0x08
block|,
comment|/**    * \brief Display the category number associated with this diagnostic, if any.    *    * The category number is displayed within brackets after the diagnostic text.    * This option corresponds to the clang flag     * \c -fdiagnostics-show-category=id.    */
name|CXDiagnostic_DisplayCategoryId
init|=
literal|0x10
block|,
comment|/**    * \brief Display the category name associated with this diagnostic, if any.    *    * The category name is displayed within brackets after the diagnostic text.    * This option corresponds to the clang flag     * \c -fdiagnostics-show-category=name.    */
name|CXDiagnostic_DisplayCategoryName
init|=
literal|0x20
block|}
enum|;
comment|/**  * \brief Format the given diagnostic in a manner that is suitable for display.  *  * This routine will format the given diagnostic to a string, rendering  * the diagnostic according to the various options given. The  * \c clang_defaultDiagnosticDisplayOptions() function returns the set of  * options that most closely mimics the behavior of the clang compiler.  *  * \param Diagnostic The diagnostic to print.  *  * \param Options A set of options that control the diagnostic display,  * created by combining \c CXDiagnosticDisplayOptions values.  *  * \returns A new string containing for formatted diagnostic.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_formatDiagnostic
parameter_list|(
name|CXDiagnostic
name|Diagnostic
parameter_list|,
name|unsigned
name|Options
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the set of display options most similar to the  * default behavior of the clang compiler.  *  * \returns A set of display options suitable for use with \c  * clang_displayDiagnostic().  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_defaultDiagnosticDisplayOptions
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * \brief Determine the severity of the given diagnostic.  */
name|CINDEX_LINKAGE
name|enum
name|CXDiagnosticSeverity
name|clang_getDiagnosticSeverity
parameter_list|(
name|CXDiagnostic
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the source location of the given diagnostic.  *  * This location is where Clang would print the caret ('^') when  * displaying the diagnostic on the command line.  */
name|CINDEX_LINKAGE
name|CXSourceLocation
name|clang_getDiagnosticLocation
parameter_list|(
name|CXDiagnostic
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the text of the given diagnostic.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_getDiagnosticSpelling
parameter_list|(
name|CXDiagnostic
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the name of the command-line option that enabled this  * diagnostic.  *  * \param Diag The diagnostic to be queried.  *  * \param Disable If non-NULL, will be set to the option that disables this  * diagnostic (if any).  *  * \returns A string that contains the command-line option used to enable this  * warning, such as "-Wconversion" or "-pedantic".   */
name|CINDEX_LINKAGE
name|CXString
name|clang_getDiagnosticOption
parameter_list|(
name|CXDiagnostic
name|Diag
parameter_list|,
name|CXString
modifier|*
name|Disable
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the category number for this diagnostic.  *  * Diagnostics can be categorized into groups along with other, related  * diagnostics (e.g., diagnostics under the same warning flag). This routine   * retrieves the category number for the given diagnostic.  *  * \returns The number of the category that contains this diagnostic, or zero  * if this diagnostic is uncategorized.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_getDiagnosticCategory
parameter_list|(
name|CXDiagnostic
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the name of a particular diagnostic category.  *  * \param Category A diagnostic category number, as returned by   * \c clang_getDiagnosticCategory().  *  * \returns The name of the given diagnostic category.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_getDiagnosticCategoryName
parameter_list|(
name|unsigned
name|Category
parameter_list|)
function_decl|;
comment|/**  * \brief Determine the number of source ranges associated with the given  * diagnostic.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_getDiagnosticNumRanges
parameter_list|(
name|CXDiagnostic
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve a source range associated with the diagnostic.  *  * A diagnostic's source ranges highlight important elements in the source  * code. On the command line, Clang displays source ranges by  * underlining them with '~' characters.  *  * \param Diagnostic the diagnostic whose range is being extracted.  *  * \param Range the zero-based index specifying which range to  *  * \returns the requested source range.  */
name|CINDEX_LINKAGE
name|CXSourceRange
name|clang_getDiagnosticRange
parameter_list|(
name|CXDiagnostic
name|Diagnostic
parameter_list|,
name|unsigned
name|Range
parameter_list|)
function_decl|;
comment|/**  * \brief Determine the number of fix-it hints associated with the  * given diagnostic.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_getDiagnosticNumFixIts
parameter_list|(
name|CXDiagnostic
name|Diagnostic
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the replacement information for a given fix-it.  *  * Fix-its are described in terms of a source range whose contents  * should be replaced by a string. This approach generalizes over  * three kinds of operations: removal of source code (the range covers  * the code to be removed and the replacement string is empty),  * replacement of source code (the range covers the code to be  * replaced and the replacement string provides the new code), and  * insertion (both the start and end of the range point at the  * insertion location, and the replacement string provides the text to  * insert).  *  * \param Diagnostic The diagnostic whose fix-its are being queried.  *  * \param FixIt The zero-based index of the fix-it.  *  * \param ReplacementRange The source range whose contents will be  * replaced with the returned replacement string. Note that source  * ranges are half-open ranges [a, b), so the source code should be  * replaced from a and up to (but not including) b.  *  * \returns A string containing text that should be replace the source  * code indicated by the \c ReplacementRange.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_getDiagnosticFixIt
parameter_list|(
name|CXDiagnostic
name|Diagnostic
parameter_list|,
name|unsigned
name|FixIt
parameter_list|,
name|CXSourceRange
modifier|*
name|ReplacementRange
parameter_list|)
function_decl|;
comment|/**  * @}  */
comment|/**  * \defgroup CINDEX_TRANSLATION_UNIT Translation unit manipulation  *  * The routines in this group provide the ability to create and destroy  * translation units from files, either by parsing the contents of the files or  * by reading in a serialized representation of a translation unit.  *  * @{  */
comment|/**  * \brief Get the original translation unit source file name.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_getTranslationUnitSpelling
parameter_list|(
name|CXTranslationUnit
name|CTUnit
parameter_list|)
function_decl|;
comment|/**  * \brief Return the CXTranslationUnit for a given source file and the provided  * command line arguments one would pass to the compiler.  *  * Note: The 'source_filename' argument is optional.  If the caller provides a  * NULL pointer, the name of the source file is expected to reside in the  * specified command line arguments.  *  * Note: When encountered in 'clang_command_line_args', the following options  * are ignored:  *  *   '-c'  *   '-emit-ast'  *   '-fsyntax-only'  *   '-o<output file>'  (both '-o' and '<output file>' are ignored)  *  * \param CIdx The index object with which the translation unit will be  * associated.  *  * \param source_filename - The name of the source file to load, or NULL if the  * source file is included in \p clang_command_line_args.  *  * \param num_clang_command_line_args The number of command-line arguments in  * \p clang_command_line_args.  *  * \param clang_command_line_args The command-line arguments that would be  * passed to the \c clang executable if it were being invoked out-of-process.  * These command-line options will be parsed and will affect how the translation  * unit is parsed. Note that the following options are ignored: '-c',  * '-emit-ast', '-fsyntex-only' (which is the default), and '-o<output file>'.  *  * \param num_unsaved_files the number of unsaved file entries in \p  * unsaved_files.  *  * \param unsaved_files the files that have not yet been saved to disk  * but may be required for code completion, including the contents of  * those files.  The contents and name of these files (as specified by  * CXUnsavedFile) are copied when necessary, so the client only needs to  * guarantee their validity until the call to this function returns.  */
name|CINDEX_LINKAGE
name|CXTranslationUnit
name|clang_createTranslationUnitFromSourceFile
parameter_list|(
name|CXIndex
name|CIdx
parameter_list|,
specifier|const
name|char
modifier|*
name|source_filename
parameter_list|,
name|int
name|num_clang_command_line_args
parameter_list|,
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|clang_command_line_args
parameter_list|,
name|unsigned
name|num_unsaved_files
parameter_list|,
name|struct
name|CXUnsavedFile
modifier|*
name|unsaved_files
parameter_list|)
function_decl|;
comment|/**  * \brief Create a translation unit from an AST file (-emit-ast).  */
name|CINDEX_LINKAGE
name|CXTranslationUnit
name|clang_createTranslationUnit
parameter_list|(
name|CXIndex
parameter_list|,
specifier|const
name|char
modifier|*
name|ast_filename
parameter_list|)
function_decl|;
comment|/**  * \brief Flags that control the creation of translation units.  *  * The enumerators in this enumeration type are meant to be bitwise  * ORed together to specify which options should be used when  * constructing the translation unit.  */
enum|enum
name|CXTranslationUnit_Flags
block|{
comment|/**    * \brief Used to indicate that no special translation-unit options are    * needed.    */
name|CXTranslationUnit_None
init|=
literal|0x0
block|,
comment|/**    * \brief Used to indicate that the parser should construct a "detailed"    * preprocessing record, including all macro definitions and instantiations.    *    * Constructing a detailed preprocessing record requires more memory    * and time to parse, since the information contained in the record    * is usually not retained. However, it can be useful for    * applications that require more detailed information about the    * behavior of the preprocessor.    */
name|CXTranslationUnit_DetailedPreprocessingRecord
init|=
literal|0x01
block|,
comment|/**    * \brief Used to indicate that the translation unit is incomplete.    *    * When a translation unit is considered "incomplete", semantic    * analysis that is typically performed at the end of the    * translation unit will be suppressed. For example, this suppresses    * the completion of tentative declarations in C and of    * instantiation of implicitly-instantiation function templates in    * C++. This option is typically used when parsing a header with the    * intent of producing a precompiled header.    */
name|CXTranslationUnit_Incomplete
init|=
literal|0x02
block|,
comment|/**    * \brief Used to indicate that the translation unit should be built with an     * implicit precompiled header for the preamble.    *    * An implicit precompiled header is used as an optimization when a    * particular translation unit is likely to be reparsed many times    * when the sources aren't changing that often. In this case, an    * implicit precompiled header will be built containing all of the    * initial includes at the top of the main file (what we refer to as    * the "preamble" of the file). In subsequent parses, if the    * preamble or the files in it have not changed, \c    * clang_reparseTranslationUnit() will re-use the implicit    * precompiled header to improve parsing performance.    */
name|CXTranslationUnit_PrecompiledPreamble
init|=
literal|0x04
block|,
comment|/**    * \brief Used to indicate that the translation unit should cache some    * code-completion results with each reparse of the source file.    *    * Caching of code-completion results is a performance optimization that    * introduces some overhead to reparsing but improves the performance of    * code-completion operations.    */
name|CXTranslationUnit_CacheCompletionResults
init|=
literal|0x08
block|,
comment|/**    * \brief Enable precompiled preambles in C++.    *    * Note: this is a *temporary* option that is available only while    * we are testing C++ precompiled preamble support.    */
name|CXTranslationUnit_CXXPrecompiledPreamble
init|=
literal|0x10
block|,
comment|/**    * \brief Enabled chained precompiled preambles in C++.    *    * Note: this is a *temporary* option that is available only while    * we are testing C++ precompiled preamble support.    */
name|CXTranslationUnit_CXXChainedPCH
init|=
literal|0x20
block|}
enum|;
comment|/**  * \brief Returns the set of flags that is suitable for parsing a translation  * unit that is being edited.  *  * The set of flags returned provide options for \c clang_parseTranslationUnit()  * to indicate that the translation unit is likely to be reparsed many times,  * either explicitly (via \c clang_reparseTranslationUnit()) or implicitly  * (e.g., by code completion (\c clang_codeCompletionAt())). The returned flag  * set contains an unspecified set of optimizations (e.g., the precompiled   * preamble) geared toward improving the performance of these routines. The  * set of optimizations enabled may change from one version to the next.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_defaultEditingTranslationUnitOptions
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * \brief Parse the given source file and the translation unit corresponding  * to that file.  *  * This routine is the main entry point for the Clang C API, providing the  * ability to parse a source file into a translation unit that can then be  * queried by other functions in the API. This routine accepts a set of  * command-line arguments so that the compilation can be configured in the same  * way that the compiler is configured on the command line.  *  * \param CIdx The index object with which the translation unit will be   * associated.  *  * \param source_filename The name of the source file to load, or NULL if the  * source file is included in \p command_line_args.  *  * \param command_line_args The command-line arguments that would be  * passed to the \c clang executable if it were being invoked out-of-process.  * These command-line options will be parsed and will affect how the translation  * unit is parsed. Note that the following options are ignored: '-c',   * '-emit-ast', '-fsyntex-only' (which is the default), and '-o<output file>'.  *  * \param num_command_line_args The number of command-line arguments in  * \p command_line_args.  *  * \param unsaved_files the files that have not yet been saved to disk  * but may be required for parsing, including the contents of  * those files.  The contents and name of these files (as specified by  * CXUnsavedFile) are copied when necessary, so the client only needs to  * guarantee their validity until the call to this function returns.  *  * \param num_unsaved_files the number of unsaved file entries in \p  * unsaved_files.  *  * \param options A bitmask of options that affects how the translation unit  * is managed but not its compilation. This should be a bitwise OR of the  * CXTranslationUnit_XXX flags.  *  * \returns A new translation unit describing the parsed code and containing  * any diagnostics produced by the compiler. If there is a failure from which  * the compiler cannot recover, returns NULL.  */
name|CINDEX_LINKAGE
name|CXTranslationUnit
name|clang_parseTranslationUnit
parameter_list|(
name|CXIndex
name|CIdx
parameter_list|,
specifier|const
name|char
modifier|*
name|source_filename
parameter_list|,
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|command_line_args
parameter_list|,
name|int
name|num_command_line_args
parameter_list|,
name|struct
name|CXUnsavedFile
modifier|*
name|unsaved_files
parameter_list|,
name|unsigned
name|num_unsaved_files
parameter_list|,
name|unsigned
name|options
parameter_list|)
function_decl|;
comment|/**  * \brief Flags that control how translation units are saved.  *  * The enumerators in this enumeration type are meant to be bitwise  * ORed together to specify which options should be used when  * saving the translation unit.  */
enum|enum
name|CXSaveTranslationUnit_Flags
block|{
comment|/**    * \brief Used to indicate that no special saving options are needed.    */
name|CXSaveTranslationUnit_None
init|=
literal|0x0
block|}
enum|;
comment|/**  * \brief Returns the set of flags that is suitable for saving a translation  * unit.  *  * The set of flags returned provide options for  * \c clang_saveTranslationUnit() by default. The returned flag  * set contains an unspecified set of options that save translation units with  * the most commonly-requested data.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_defaultSaveOptions
parameter_list|(
name|CXTranslationUnit
name|TU
parameter_list|)
function_decl|;
comment|/**  * \brief Saves a translation unit into a serialized representation of  * that translation unit on disk.  *  * Any translation unit that was parsed without error can be saved  * into a file. The translation unit can then be deserialized into a  * new \c CXTranslationUnit with \c clang_createTranslationUnit() or,  * if it is an incomplete translation unit that corresponds to a  * header, used as a precompiled header when parsing other translation  * units.  *  * \param TU The translation unit to save.  *  * \param FileName The file to which the translation unit will be saved.  *  * \param options A bitmask of options that affects how the translation unit  * is saved. This should be a bitwise OR of the  * CXSaveTranslationUnit_XXX flags.  *  * \returns Zero if the translation unit was saved successfully, a  * non-zero value otherwise.  */
name|CINDEX_LINKAGE
name|int
name|clang_saveTranslationUnit
parameter_list|(
name|CXTranslationUnit
name|TU
parameter_list|,
specifier|const
name|char
modifier|*
name|FileName
parameter_list|,
name|unsigned
name|options
parameter_list|)
function_decl|;
comment|/**  * \brief Destroy the specified CXTranslationUnit object.  */
name|CINDEX_LINKAGE
name|void
name|clang_disposeTranslationUnit
parameter_list|(
name|CXTranslationUnit
parameter_list|)
function_decl|;
comment|/**  * \brief Flags that control the reparsing of translation units.  *  * The enumerators in this enumeration type are meant to be bitwise  * ORed together to specify which options should be used when  * reparsing the translation unit.  */
enum|enum
name|CXReparse_Flags
block|{
comment|/**    * \brief Used to indicate that no special reparsing options are needed.    */
name|CXReparse_None
init|=
literal|0x0
block|}
enum|;
comment|/**  * \brief Returns the set of flags that is suitable for reparsing a translation  * unit.  *  * The set of flags returned provide options for  * \c clang_reparseTranslationUnit() by default. The returned flag  * set contains an unspecified set of optimizations geared toward common uses  * of reparsing. The set of optimizations enabled may change from one version   * to the next.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_defaultReparseOptions
parameter_list|(
name|CXTranslationUnit
name|TU
parameter_list|)
function_decl|;
comment|/**  * \brief Reparse the source files that produced this translation unit.  *  * This routine can be used to re-parse the source files that originally  * created the given translation unit, for example because those source files  * have changed (either on disk or as passed via \p unsaved_files). The  * source code will be reparsed with the same command-line options as it  * was originally parsed.   *  * Reparsing a translation unit invalidates all cursors and source locations  * that refer into that translation unit. This makes reparsing a translation  * unit semantically equivalent to destroying the translation unit and then  * creating a new translation unit with the same command-line arguments.  * However, it may be more efficient to reparse a translation   * unit using this routine.  *  * \param TU The translation unit whose contents will be re-parsed. The  * translation unit must originally have been built with   * \c clang_createTranslationUnitFromSourceFile().  *  * \param num_unsaved_files The number of unsaved file entries in \p  * unsaved_files.  *  * \param unsaved_files The files that have not yet been saved to disk  * but may be required for parsing, including the contents of  * those files.  The contents and name of these files (as specified by  * CXUnsavedFile) are copied when necessary, so the client only needs to  * guarantee their validity until the call to this function returns.  *   * \param options A bitset of options composed of the flags in CXReparse_Flags.  * The function \c clang_defaultReparseOptions() produces a default set of  * options recommended for most uses, based on the translation unit.  *  * \returns 0 if the sources could be reparsed. A non-zero value will be  * returned if reparsing was impossible, such that the translation unit is  * invalid. In such cases, the only valid call for \p TU is   * \c clang_disposeTranslationUnit(TU).  */
name|CINDEX_LINKAGE
name|int
name|clang_reparseTranslationUnit
parameter_list|(
name|CXTranslationUnit
name|TU
parameter_list|,
name|unsigned
name|num_unsaved_files
parameter_list|,
name|struct
name|CXUnsavedFile
modifier|*
name|unsaved_files
parameter_list|,
name|unsigned
name|options
parameter_list|)
function_decl|;
comment|/**  * @}  */
comment|/**  * \brief Describes the kind of entity that a cursor refers to.  */
enum|enum
name|CXCursorKind
block|{
comment|/* Declarations */
comment|/**    * \brief A declaration whose specific kind is not exposed via this    * interface.    *    * Unexposed declarations have the same operations as any other kind    * of declaration; one can extract their location information,    * spelling, find their definitions, etc. However, the specific kind    * of the declaration is not reported.    */
name|CXCursor_UnexposedDecl
init|=
literal|1
block|,
comment|/** \brief A C or C++ struct. */
name|CXCursor_StructDecl
init|=
literal|2
block|,
comment|/** \brief A C or C++ union. */
name|CXCursor_UnionDecl
init|=
literal|3
block|,
comment|/** \brief A C++ class. */
name|CXCursor_ClassDecl
init|=
literal|4
block|,
comment|/** \brief An enumeration. */
name|CXCursor_EnumDecl
init|=
literal|5
block|,
comment|/**    * \brief A field (in C) or non-static data member (in C++) in a    * struct, union, or C++ class.    */
name|CXCursor_FieldDecl
init|=
literal|6
block|,
comment|/** \brief An enumerator constant. */
name|CXCursor_EnumConstantDecl
init|=
literal|7
block|,
comment|/** \brief A function. */
name|CXCursor_FunctionDecl
init|=
literal|8
block|,
comment|/** \brief A variable. */
name|CXCursor_VarDecl
init|=
literal|9
block|,
comment|/** \brief A function or method parameter. */
name|CXCursor_ParmDecl
init|=
literal|10
block|,
comment|/** \brief An Objective-C @interface. */
name|CXCursor_ObjCInterfaceDecl
init|=
literal|11
block|,
comment|/** \brief An Objective-C @interface for a category. */
name|CXCursor_ObjCCategoryDecl
init|=
literal|12
block|,
comment|/** \brief An Objective-C @protocol declaration. */
name|CXCursor_ObjCProtocolDecl
init|=
literal|13
block|,
comment|/** \brief An Objective-C @property declaration. */
name|CXCursor_ObjCPropertyDecl
init|=
literal|14
block|,
comment|/** \brief An Objective-C instance variable. */
name|CXCursor_ObjCIvarDecl
init|=
literal|15
block|,
comment|/** \brief An Objective-C instance method. */
name|CXCursor_ObjCInstanceMethodDecl
init|=
literal|16
block|,
comment|/** \brief An Objective-C class method. */
name|CXCursor_ObjCClassMethodDecl
init|=
literal|17
block|,
comment|/** \brief An Objective-C @implementation. */
name|CXCursor_ObjCImplementationDecl
init|=
literal|18
block|,
comment|/** \brief An Objective-C @implementation for a category. */
name|CXCursor_ObjCCategoryImplDecl
init|=
literal|19
block|,
comment|/** \brief A typedef */
name|CXCursor_TypedefDecl
init|=
literal|20
block|,
comment|/** \brief A C++ class method. */
name|CXCursor_CXXMethod
init|=
literal|21
block|,
comment|/** \brief A C++ namespace. */
name|CXCursor_Namespace
init|=
literal|22
block|,
comment|/** \brief A linkage specification, e.g. 'extern "C"'. */
name|CXCursor_LinkageSpec
init|=
literal|23
block|,
comment|/** \brief A C++ constructor. */
name|CXCursor_Constructor
init|=
literal|24
block|,
comment|/** \brief A C++ destructor. */
name|CXCursor_Destructor
init|=
literal|25
block|,
comment|/** \brief A C++ conversion function. */
name|CXCursor_ConversionFunction
init|=
literal|26
block|,
comment|/** \brief A C++ template type parameter. */
name|CXCursor_TemplateTypeParameter
init|=
literal|27
block|,
comment|/** \brief A C++ non-type template parameter. */
name|CXCursor_NonTypeTemplateParameter
init|=
literal|28
block|,
comment|/** \brief A C++ template template parameter. */
name|CXCursor_TemplateTemplateParameter
init|=
literal|29
block|,
comment|/** \brief A C++ function template. */
name|CXCursor_FunctionTemplate
init|=
literal|30
block|,
comment|/** \brief A C++ class template. */
name|CXCursor_ClassTemplate
init|=
literal|31
block|,
comment|/** \brief A C++ class template partial specialization. */
name|CXCursor_ClassTemplatePartialSpecialization
init|=
literal|32
block|,
comment|/** \brief A C++ namespace alias declaration. */
name|CXCursor_NamespaceAlias
init|=
literal|33
block|,
comment|/** \brief A C++ using directive. */
name|CXCursor_UsingDirective
init|=
literal|34
block|,
comment|/** \brief A using declaration. */
name|CXCursor_UsingDeclaration
init|=
literal|35
block|,
name|CXCursor_FirstDecl
init|=
name|CXCursor_UnexposedDecl
block|,
name|CXCursor_LastDecl
init|=
name|CXCursor_UsingDeclaration
block|,
comment|/* References */
name|CXCursor_FirstRef
init|=
literal|40
block|,
comment|/* Decl references */
name|CXCursor_ObjCSuperClassRef
init|=
literal|40
block|,
name|CXCursor_ObjCProtocolRef
init|=
literal|41
block|,
name|CXCursor_ObjCClassRef
init|=
literal|42
block|,
comment|/**    * \brief A reference to a type declaration.    *    * A type reference occurs anywhere where a type is named but not    * declared. For example, given:    *    * \code    * typedef unsigned size_type;    * size_type size;    * \endcode    *    * The typedef is a declaration of size_type (CXCursor_TypedefDecl),    * while the type of the variable "size" is referenced. The cursor    * referenced by the type of size is the typedef for size_type.    */
name|CXCursor_TypeRef
init|=
literal|43
block|,
name|CXCursor_CXXBaseSpecifier
init|=
literal|44
block|,
comment|/**     * \brief A reference to a class template, function template, template    * template parameter, or class template partial specialization.    */
name|CXCursor_TemplateRef
init|=
literal|45
block|,
comment|/**    * \brief A reference to a namespace or namespace alias.    */
name|CXCursor_NamespaceRef
init|=
literal|46
block|,
comment|/**    * \brief A reference to a member of a struct, union, or class that occurs in     * some non-expression context, e.g., a designated initializer.    */
name|CXCursor_MemberRef
init|=
literal|47
block|,
comment|/**    * \brief A reference to a labeled statement.    *    * This cursor kind is used to describe the jump to "start_over" in the     * goto statement in the following example:    *    * \code    *   start_over:    *     ++counter;    *    *     goto start_over;    * \endcode    *    * A label reference cursor refers to a label statement.    */
name|CXCursor_LabelRef
init|=
literal|48
block|,
comment|/**    * \brief A reference to a set of overloaded functions or function templates    * that has not yet been resolved to a specific function or function template.    *    * An overloaded declaration reference cursor occurs in C++ templates where    * a dependent name refers to a function. For example:    *    * \code    * template<typename T> void swap(T&, T&);    *    * struct X { ... };    * void swap(X&, X&);    *    * template<typename T>    * void reverse(T* first, T* last) {    *   while (first< last - 1) {    *     swap(*first, *--last);    *     ++first;    *   }    * }    *    * struct Y { };    * void swap(Y&, Y&);    * \endcode    *    * Here, the identifier "swap" is associated with an overloaded declaration    * reference. In the template definition, "swap" refers to either of the two    * "swap" functions declared above, so both results will be available. At    * instantiation time, "swap" may also refer to other functions found via    * argument-dependent lookup (e.g., the "swap" function at the end of the    * example).    *    * The functions \c clang_getNumOverloadedDecls() and     * \c clang_getOverloadedDecl() can be used to retrieve the definitions    * referenced by this cursor.    */
name|CXCursor_OverloadedDeclRef
init|=
literal|49
block|,
name|CXCursor_LastRef
init|=
name|CXCursor_OverloadedDeclRef
block|,
comment|/* Error conditions */
name|CXCursor_FirstInvalid
init|=
literal|70
block|,
name|CXCursor_InvalidFile
init|=
literal|70
block|,
name|CXCursor_NoDeclFound
init|=
literal|71
block|,
name|CXCursor_NotImplemented
init|=
literal|72
block|,
name|CXCursor_InvalidCode
init|=
literal|73
block|,
name|CXCursor_LastInvalid
init|=
name|CXCursor_InvalidCode
block|,
comment|/* Expressions */
name|CXCursor_FirstExpr
init|=
literal|100
block|,
comment|/**    * \brief An expression whose specific kind is not exposed via this    * interface.    *    * Unexposed expressions have the same operations as any other kind    * of expression; one can extract their location information,    * spelling, children, etc. However, the specific kind of the    * expression is not reported.    */
name|CXCursor_UnexposedExpr
init|=
literal|100
block|,
comment|/**    * \brief An expression that refers to some value declaration, such    * as a function, varible, or enumerator.    */
name|CXCursor_DeclRefExpr
init|=
literal|101
block|,
comment|/**    * \brief An expression that refers to a member of a struct, union,    * class, Objective-C class, etc.    */
name|CXCursor_MemberRefExpr
init|=
literal|102
block|,
comment|/** \brief An expression that calls a function. */
name|CXCursor_CallExpr
init|=
literal|103
block|,
comment|/** \brief An expression that sends a message to an Objective-C    object or class. */
name|CXCursor_ObjCMessageExpr
init|=
literal|104
block|,
comment|/** \brief An expression that represents a block literal. */
name|CXCursor_BlockExpr
init|=
literal|105
block|,
name|CXCursor_LastExpr
init|=
literal|105
block|,
comment|/* Statements */
name|CXCursor_FirstStmt
init|=
literal|200
block|,
comment|/**    * \brief A statement whose specific kind is not exposed via this    * interface.    *    * Unexposed statements have the same operations as any other kind of    * statement; one can extract their location information, spelling,    * children, etc. However, the specific kind of the statement is not    * reported.    */
name|CXCursor_UnexposedStmt
init|=
literal|200
block|,
comment|/** \brief A labelled statement in a function.     *    * This cursor kind is used to describe the "start_over:" label statement in     * the following example:    *    * \code    *   start_over:    *     ++counter;    * \endcode    *    */
name|CXCursor_LabelStmt
init|=
literal|201
block|,
name|CXCursor_LastStmt
init|=
name|CXCursor_LabelStmt
block|,
comment|/**    * \brief Cursor that represents the translation unit itself.    *    * The translation unit cursor exists primarily to act as the root    * cursor for traversing the contents of a translation unit.    */
name|CXCursor_TranslationUnit
init|=
literal|300
block|,
comment|/* Attributes */
name|CXCursor_FirstAttr
init|=
literal|400
block|,
comment|/**    * \brief An attribute whose specific kind is not exposed via this    * interface.    */
name|CXCursor_UnexposedAttr
init|=
literal|400
block|,
name|CXCursor_IBActionAttr
init|=
literal|401
block|,
name|CXCursor_IBOutletAttr
init|=
literal|402
block|,
name|CXCursor_IBOutletCollectionAttr
init|=
literal|403
block|,
name|CXCursor_LastAttr
init|=
name|CXCursor_IBOutletCollectionAttr
block|,
comment|/* Preprocessing */
name|CXCursor_PreprocessingDirective
init|=
literal|500
block|,
name|CXCursor_MacroDefinition
init|=
literal|501
block|,
name|CXCursor_MacroInstantiation
init|=
literal|502
block|,
name|CXCursor_InclusionDirective
init|=
literal|503
block|,
name|CXCursor_FirstPreprocessing
init|=
name|CXCursor_PreprocessingDirective
block|,
name|CXCursor_LastPreprocessing
init|=
name|CXCursor_InclusionDirective
block|}
enum|;
comment|/**  * \brief A cursor representing some element in the abstract syntax tree for  * a translation unit.  *  * The cursor abstraction unifies the different kinds of entities in a  * program--declaration, statements, expressions, references to declarations,  * etc.--under a single "cursor" abstraction with a common set of operations.  * Common operation for a cursor include: getting the physical location in  * a source file where the cursor points, getting the name associated with a  * cursor, and retrieving cursors for any child nodes of a particular cursor.  *  * Cursors can be produced in two specific ways.  * clang_getTranslationUnitCursor() produces a cursor for a translation unit,  * from which one can use clang_visitChildren() to explore the rest of the  * translation unit. clang_getCursor() maps from a physical source location  * to the entity that resides at that location, allowing one to map from the  * source code into the AST.  */
typedef|typedef
struct|struct
block|{
name|enum
name|CXCursorKind
name|kind
decl_stmt|;
name|void
modifier|*
name|data
index|[
literal|3
index|]
decl_stmt|;
block|}
name|CXCursor
typedef|;
comment|/**  * \defgroup CINDEX_CURSOR_MANIP Cursor manipulations  *  * @{  */
comment|/**  * \brief Retrieve the NULL cursor, which represents no entity.  */
name|CINDEX_LINKAGE
name|CXCursor
name|clang_getNullCursor
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the cursor that represents the given translation unit.  *  * The translation unit cursor can be used to start traversing the  * various declarations within the given translation unit.  */
name|CINDEX_LINKAGE
name|CXCursor
name|clang_getTranslationUnitCursor
parameter_list|(
name|CXTranslationUnit
parameter_list|)
function_decl|;
comment|/**  * \brief Determine whether two cursors are equivalent.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_equalCursors
parameter_list|(
name|CXCursor
parameter_list|,
name|CXCursor
parameter_list|)
function_decl|;
comment|/**  * \brief Compute a hash value for the given cursor.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_hashCursor
parameter_list|(
name|CXCursor
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the kind of the given cursor.  */
name|CINDEX_LINKAGE
name|enum
name|CXCursorKind
name|clang_getCursorKind
parameter_list|(
name|CXCursor
parameter_list|)
function_decl|;
comment|/**  * \brief Determine whether the given cursor kind represents a declaration.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_isDeclaration
parameter_list|(
name|enum
name|CXCursorKind
parameter_list|)
function_decl|;
comment|/**  * \brief Determine whether the given cursor kind represents a simple  * reference.  *  * Note that other kinds of cursors (such as expressions) can also refer to  * other cursors. Use clang_getCursorReferenced() to determine whether a  * particular cursor refers to another entity.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_isReference
parameter_list|(
name|enum
name|CXCursorKind
parameter_list|)
function_decl|;
comment|/**  * \brief Determine whether the given cursor kind represents an expression.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_isExpression
parameter_list|(
name|enum
name|CXCursorKind
parameter_list|)
function_decl|;
comment|/**  * \brief Determine whether the given cursor kind represents a statement.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_isStatement
parameter_list|(
name|enum
name|CXCursorKind
parameter_list|)
function_decl|;
comment|/**  * \brief Determine whether the given cursor kind represents an invalid  * cursor.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_isInvalid
parameter_list|(
name|enum
name|CXCursorKind
parameter_list|)
function_decl|;
comment|/**  * \brief Determine whether the given cursor kind represents a translation  * unit.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_isTranslationUnit
parameter_list|(
name|enum
name|CXCursorKind
parameter_list|)
function_decl|;
comment|/***  * \brief Determine whether the given cursor represents a preprocessing  * element, such as a preprocessor directive or macro instantiation.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_isPreprocessing
parameter_list|(
name|enum
name|CXCursorKind
parameter_list|)
function_decl|;
comment|/***  * \brief Determine whether the given cursor represents a currently  *  unexposed piece of the AST (e.g., CXCursor_UnexposedStmt).  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_isUnexposed
parameter_list|(
name|enum
name|CXCursorKind
parameter_list|)
function_decl|;
comment|/**  * \brief Describe the linkage of the entity referred to by a cursor.  */
enum|enum
name|CXLinkageKind
block|{
comment|/** \brief This value indicates that no linkage information is available    * for a provided CXCursor. */
name|CXLinkage_Invalid
block|,
comment|/**    * \brief This is the linkage for variables, parameters, and so on that    *  have automatic storage.  This covers normal (non-extern) local variables.    */
name|CXLinkage_NoLinkage
block|,
comment|/** \brief This is the linkage for static variables and static functions. */
name|CXLinkage_Internal
block|,
comment|/** \brief This is the linkage for entities with external linkage that live    * in C++ anonymous namespaces.*/
name|CXLinkage_UniqueExternal
block|,
comment|/** \brief This is the linkage for entities with true, external linkage. */
name|CXLinkage_External
block|}
enum|;
comment|/**  * \brief Determine the linkage of the entity referred to by a given cursor.  */
name|CINDEX_LINKAGE
name|enum
name|CXLinkageKind
name|clang_getCursorLinkage
parameter_list|(
name|CXCursor
name|cursor
parameter_list|)
function_decl|;
comment|/**  * \brief Determine the availability of the entity that this cursor refers to.  *  * \param cursor The cursor to query.  *  * \returns The availability of the cursor.  */
name|CINDEX_LINKAGE
name|enum
name|CXAvailabilityKind
name|clang_getCursorAvailability
parameter_list|(
name|CXCursor
name|cursor
parameter_list|)
function_decl|;
comment|/**  * \brief Describe the "language" of the entity referred to by a cursor.  */
name|CINDEX_LINKAGE
name|enum
name|CXLanguageKind
block|{
name|CXLanguage_Invalid
operator|=
literal|0
operator|,
name|CXLanguage_C
operator|,
name|CXLanguage_ObjC
operator|,
name|CXLanguage_CPlusPlus
block|}
empty_stmt|;
comment|/**  * \brief Determine the "language" of the entity referred to by a given cursor.  */
name|CINDEX_LINKAGE
name|enum
name|CXLanguageKind
name|clang_getCursorLanguage
parameter_list|(
name|CXCursor
name|cursor
parameter_list|)
function_decl|;
comment|/**  * \brief A fast container representing a set of CXCursors.  */
typedef|typedef
name|struct
name|CXCursorSetImpl
modifier|*
name|CXCursorSet
typedef|;
comment|/**  * \brief Creates an empty CXCursorSet.  */
name|CINDEX_LINKAGE
name|CXCursorSet
name|clang_createCXCursorSet
parameter_list|()
function_decl|;
comment|/**  * \brief Disposes a CXCursorSet and releases its associated memory.  */
name|CINDEX_LINKAGE
name|void
name|clang_disposeCXCursorSet
parameter_list|(
name|CXCursorSet
name|cset
parameter_list|)
function_decl|;
comment|/**  * \brief Queries a CXCursorSet to see if it contains a specific CXCursor.  *  * \returns non-zero if the set contains the specified cursor. */
name|CINDEX_LINKAGE
name|unsigned
name|clang_CXCursorSet_contains
parameter_list|(
name|CXCursorSet
name|cset
parameter_list|,
name|CXCursor
name|cursor
parameter_list|)
function_decl|;
comment|/**  * \brief Inserts a CXCursor into a CXCursorSet.  *  * \returns zero if the CXCursor was already in the set, and non-zero otherwise. */
name|CINDEX_LINKAGE
name|unsigned
name|clang_CXCursorSet_insert
parameter_list|(
name|CXCursorSet
name|cset
parameter_list|,
name|CXCursor
name|cursor
parameter_list|)
function_decl|;
comment|/**  * \brief Determine the semantic parent of the given cursor.  *  * The semantic parent of a cursor is the cursor that semantically contains  * the given \p cursor. For many declarations, the lexical and semantic parents  * are equivalent (the lexical parent is returned by   * \c clang_getCursorLexicalParent()). They diverge when declarations or  * definitions are provided out-of-line. For example:  *  * \code  * class C {  *  void f();  * };  *  * void C::f() { }  * \endcode  *  * In the out-of-line definition of \c C::f, the semantic parent is the   * the class \c C, of which this function is a member. The lexical parent is  * the place where the declaration actually occurs in the source code; in this  * case, the definition occurs in the translation unit. In general, the   * lexical parent for a given entity can change without affecting the semantics  * of the program, and the lexical parent of different declarations of the  * same entity may be different. Changing the semantic parent of a declaration,  * on the other hand, can have a major impact on semantics, and redeclarations  * of a particular entity should all have the same semantic context.  *  * In the example above, both declarations of \c C::f have \c C as their  * semantic context, while the lexical context of the first \c C::f is \c C  * and the lexical context of the second \c C::f is the translation unit.  *  * For global declarations, the semantic parent is the translation unit.  */
name|CINDEX_LINKAGE
name|CXCursor
name|clang_getCursorSemanticParent
parameter_list|(
name|CXCursor
name|cursor
parameter_list|)
function_decl|;
comment|/**  * \brief Determine the lexical parent of the given cursor.  *  * The lexical parent of a cursor is the cursor in which the given \p cursor  * was actually written. For many declarations, the lexical and semantic parents  * are equivalent (the semantic parent is returned by   * \c clang_getCursorSemanticParent()). They diverge when declarations or  * definitions are provided out-of-line. For example:  *  * \code  * class C {  *  void f();  * };  *  * void C::f() { }  * \endcode  *  * In the out-of-line definition of \c C::f, the semantic parent is the   * the class \c C, of which this function is a member. The lexical parent is  * the place where the declaration actually occurs in the source code; in this  * case, the definition occurs in the translation unit. In general, the   * lexical parent for a given entity can change without affecting the semantics  * of the program, and the lexical parent of different declarations of the  * same entity may be different. Changing the semantic parent of a declaration,  * on the other hand, can have a major impact on semantics, and redeclarations  * of a particular entity should all have the same semantic context.  *  * In the example above, both declarations of \c C::f have \c C as their  * semantic context, while the lexical context of the first \c C::f is \c C  * and the lexical context of the second \c C::f is the translation unit.  *  * For declarations written in the global scope, the lexical parent is  * the translation unit.  */
name|CINDEX_LINKAGE
name|CXCursor
name|clang_getCursorLexicalParent
parameter_list|(
name|CXCursor
name|cursor
parameter_list|)
function_decl|;
comment|/**  * \brief Determine the set of methods that are overridden by the given  * method.  *  * In both Objective-C and C++, a method (aka virtual member function,  * in C++) can override a virtual method in a base class. For  * Objective-C, a method is said to override any method in the class's  * interface (if we're coming from an implementation), its protocols,  * or its categories, that has the same selector and is of the same  * kind (class or instance). If no such method exists, the search  * continues to the class's superclass, its protocols, and its  * categories, and so on.  *  * For C++, a virtual member function overrides any virtual member  * function with the same signature that occurs in its base  * classes. With multiple inheritance, a virtual member function can  * override several virtual member functions coming from different  * base classes.  *  * In all cases, this function determines the immediate overridden  * method, rather than all of the overridden methods. For example, if  * a method is originally declared in a class A, then overridden in B  * (which in inherits from A) and also in C (which inherited from B),  * then the only overridden method returned from this function when  * invoked on C's method will be B's method. The client may then  * invoke this function again, given the previously-found overridden  * methods, to map out the complete method-override set.  *  * \param cursor A cursor representing an Objective-C or C++  * method. This routine will compute the set of methods that this  * method overrides.  *   * \param overridden A pointer whose pointee will be replaced with a  * pointer to an array of cursors, representing the set of overridden  * methods. If there are no overridden methods, the pointee will be  * set to NULL. The pointee must be freed via a call to   * \c clang_disposeOverriddenCursors().  *  * \param num_overridden A pointer to the number of overridden  * functions, will be set to the number of overridden functions in the  * array pointed to by \p overridden.  */
name|CINDEX_LINKAGE
name|void
name|clang_getOverriddenCursors
parameter_list|(
name|CXCursor
name|cursor
parameter_list|,
name|CXCursor
modifier|*
modifier|*
name|overridden
parameter_list|,
name|unsigned
modifier|*
name|num_overridden
parameter_list|)
function_decl|;
comment|/**  * \brief Free the set of overridden cursors returned by \c  * clang_getOverriddenCursors().  */
name|CINDEX_LINKAGE
name|void
name|clang_disposeOverriddenCursors
parameter_list|(
name|CXCursor
modifier|*
name|overridden
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the file that is included by the given inclusion directive  * cursor.  */
name|CINDEX_LINKAGE
name|CXFile
name|clang_getIncludedFile
parameter_list|(
name|CXCursor
name|cursor
parameter_list|)
function_decl|;
comment|/**  * @}  */
comment|/**  * \defgroup CINDEX_CURSOR_SOURCE Mapping between cursors and source code  *  * Cursors represent a location within the Abstract Syntax Tree (AST). These  * routines help map between cursors and the physical locations where the  * described entities occur in the source code. The mapping is provided in  * both directions, so one can map from source code to the AST and back.  *  * @{  */
comment|/**  * \brief Map a source location to the cursor that describes the entity at that  * location in the source code.  *  * clang_getCursor() maps an arbitrary source location within a translation  * unit down to the most specific cursor that describes the entity at that  * location. For example, given an expression \c x + y, invoking  * clang_getCursor() with a source location pointing to "x" will return the  * cursor for "x"; similarly for "y". If the cursor points anywhere between  * "x" or "y" (e.g., on the + or the whitespace around it), clang_getCursor()  * will return a cursor referring to the "+" expression.  *  * \returns a cursor representing the entity at the given source location, or  * a NULL cursor if no such entity can be found.  */
name|CINDEX_LINKAGE
name|CXCursor
name|clang_getCursor
parameter_list|(
name|CXTranslationUnit
parameter_list|,
name|CXSourceLocation
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the physical location of the source constructor referenced  * by the given cursor.  *  * The location of a declaration is typically the location of the name of that  * declaration, where the name of that declaration would occur if it is  * unnamed, or some keyword that introduces that particular declaration.  * The location of a reference is where that reference occurs within the  * source code.  */
name|CINDEX_LINKAGE
name|CXSourceLocation
name|clang_getCursorLocation
parameter_list|(
name|CXCursor
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the physical extent of the source construct referenced by  * the given cursor.  *  * The extent of a cursor starts with the file/line/column pointing at the  * first character within the source construct that the cursor refers to and  * ends with the last character withinin that source construct. For a  * declaration, the extent covers the declaration itself. For a reference,  * the extent covers the location of the reference (e.g., where the referenced  * entity was actually used).  */
name|CINDEX_LINKAGE
name|CXSourceRange
name|clang_getCursorExtent
parameter_list|(
name|CXCursor
parameter_list|)
function_decl|;
comment|/**  * @}  */
comment|/**  * \defgroup CINDEX_TYPES Type information for CXCursors  *  * @{  */
comment|/**  * \brief Describes the kind of type  */
enum|enum
name|CXTypeKind
block|{
comment|/**    * \brief Reprents an invalid type (e.g., where no type is available).    */
name|CXType_Invalid
init|=
literal|0
block|,
comment|/**    * \brief A type whose specific kind is not exposed via this    * interface.    */
name|CXType_Unexposed
init|=
literal|1
block|,
comment|/* Builtin types */
name|CXType_Void
init|=
literal|2
block|,
name|CXType_Bool
init|=
literal|3
block|,
name|CXType_Char_U
init|=
literal|4
block|,
name|CXType_UChar
init|=
literal|5
block|,
name|CXType_Char16
init|=
literal|6
block|,
name|CXType_Char32
init|=
literal|7
block|,
name|CXType_UShort
init|=
literal|8
block|,
name|CXType_UInt
init|=
literal|9
block|,
name|CXType_ULong
init|=
literal|10
block|,
name|CXType_ULongLong
init|=
literal|11
block|,
name|CXType_UInt128
init|=
literal|12
block|,
name|CXType_Char_S
init|=
literal|13
block|,
name|CXType_SChar
init|=
literal|14
block|,
name|CXType_WChar
init|=
literal|15
block|,
name|CXType_Short
init|=
literal|16
block|,
name|CXType_Int
init|=
literal|17
block|,
name|CXType_Long
init|=
literal|18
block|,
name|CXType_LongLong
init|=
literal|19
block|,
name|CXType_Int128
init|=
literal|20
block|,
name|CXType_Float
init|=
literal|21
block|,
name|CXType_Double
init|=
literal|22
block|,
name|CXType_LongDouble
init|=
literal|23
block|,
name|CXType_NullPtr
init|=
literal|24
block|,
name|CXType_Overload
init|=
literal|25
block|,
name|CXType_Dependent
init|=
literal|26
block|,
name|CXType_ObjCId
init|=
literal|27
block|,
name|CXType_ObjCClass
init|=
literal|28
block|,
name|CXType_ObjCSel
init|=
literal|29
block|,
name|CXType_FirstBuiltin
init|=
name|CXType_Void
block|,
name|CXType_LastBuiltin
init|=
name|CXType_ObjCSel
block|,
name|CXType_Complex
init|=
literal|100
block|,
name|CXType_Pointer
init|=
literal|101
block|,
name|CXType_BlockPointer
init|=
literal|102
block|,
name|CXType_LValueReference
init|=
literal|103
block|,
name|CXType_RValueReference
init|=
literal|104
block|,
name|CXType_Record
init|=
literal|105
block|,
name|CXType_Enum
init|=
literal|106
block|,
name|CXType_Typedef
init|=
literal|107
block|,
name|CXType_ObjCInterface
init|=
literal|108
block|,
name|CXType_ObjCObjectPointer
init|=
literal|109
block|,
name|CXType_FunctionNoProto
init|=
literal|110
block|,
name|CXType_FunctionProto
init|=
literal|111
block|}
enum|;
comment|/**  * \brief The type of an element in the abstract syntax tree.  *  */
typedef|typedef
struct|struct
block|{
name|enum
name|CXTypeKind
name|kind
decl_stmt|;
name|void
modifier|*
name|data
index|[
literal|2
index|]
decl_stmt|;
block|}
name|CXType
typedef|;
comment|/**  * \brief Retrieve the type of a CXCursor (if any).  */
name|CINDEX_LINKAGE
name|CXType
name|clang_getCursorType
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * \determine Determine whether two CXTypes represent the same type.  *  * \returns non-zero if the CXTypes represent the same type and              zero otherwise.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_equalTypes
parameter_list|(
name|CXType
name|A
parameter_list|,
name|CXType
name|B
parameter_list|)
function_decl|;
comment|/**  * \brief Return the canonical type for a CXType.  *  * Clang's type system explicitly models typedefs and all the ways  * a specific type can be represented.  The canonical type is the underlying  * type with all the "sugar" removed.  For example, if 'T' is a typedef  * for 'int', the canonical type for 'T' would be 'int'.  */
name|CINDEX_LINKAGE
name|CXType
name|clang_getCanonicalType
parameter_list|(
name|CXType
name|T
parameter_list|)
function_decl|;
comment|/**  *  \determine Determine whether a CXType has the "const" qualifier set,   *  without looking through typedefs that may have added "const" at a different level.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_isConstQualifiedType
parameter_list|(
name|CXType
name|T
parameter_list|)
function_decl|;
comment|/**  *  \determine Determine whether a CXType has the "volatile" qualifier set,  *  without looking through typedefs that may have added "volatile" at a different level.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_isVolatileQualifiedType
parameter_list|(
name|CXType
name|T
parameter_list|)
function_decl|;
comment|/**  *  \determine Determine whether a CXType has the "restrict" qualifier set,  *  without looking through typedefs that may have added "restrict" at a different level.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_isRestrictQualifiedType
parameter_list|(
name|CXType
name|T
parameter_list|)
function_decl|;
comment|/**  * \brief For pointer types, returns the type of the pointee.  *  */
name|CINDEX_LINKAGE
name|CXType
name|clang_getPointeeType
parameter_list|(
name|CXType
name|T
parameter_list|)
function_decl|;
comment|/**  * \brief Return the cursor for the declaration of the given type.  */
name|CINDEX_LINKAGE
name|CXCursor
name|clang_getTypeDeclaration
parameter_list|(
name|CXType
name|T
parameter_list|)
function_decl|;
comment|/**  * Returns the Objective-C type encoding for the specified declaration.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_getDeclObjCTypeEncoding
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the spelling of a given CXTypeKind.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_getTypeKindSpelling
parameter_list|(
name|enum
name|CXTypeKind
name|K
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the result type associated with a function type.  */
name|CINDEX_LINKAGE
name|CXType
name|clang_getResultType
parameter_list|(
name|CXType
name|T
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the result type associated with a given cursor.  This only  *  returns a valid type of the cursor refers to a function or method.  */
name|CINDEX_LINKAGE
name|CXType
name|clang_getCursorResultType
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * \brief Return 1 if the CXType is a POD (plain old data) type, and 0  *  otherwise.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_isPODType
parameter_list|(
name|CXType
name|T
parameter_list|)
function_decl|;
comment|/**  * \brief Returns 1 if the base class specified by the cursor with kind  *   CX_CXXBaseSpecifier is virtual.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_isVirtualBase
parameter_list|(
name|CXCursor
parameter_list|)
function_decl|;
comment|/**  * \brief Represents the C++ access control level to a base class for a  * cursor with kind CX_CXXBaseSpecifier.  */
enum|enum
name|CX_CXXAccessSpecifier
block|{
name|CX_CXXInvalidAccessSpecifier
block|,
name|CX_CXXPublic
block|,
name|CX_CXXProtected
block|,
name|CX_CXXPrivate
block|}
enum|;
comment|/**  * \brief Returns the access control level for the C++ base specifier  *  represented by a cursor with kind CX_CXXBaseSpecifier.  */
name|CINDEX_LINKAGE
name|enum
name|CX_CXXAccessSpecifier
name|clang_getCXXAccessSpecifier
parameter_list|(
name|CXCursor
parameter_list|)
function_decl|;
comment|/**  * \brief Determine the number of overloaded declarations referenced by a   * \c CXCursor_OverloadedDeclRef cursor.  *  * \param cursor The cursor whose overloaded declarations are being queried.  *  * \returns The number of overloaded declarations referenced by \c cursor. If it  * is not a \c CXCursor_OverloadedDeclRef cursor, returns 0.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_getNumOverloadedDecls
parameter_list|(
name|CXCursor
name|cursor
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve a cursor for one of the overloaded declarations referenced  * by a \c CXCursor_OverloadedDeclRef cursor.  *  * \param cursor The cursor whose overloaded declarations are being queried.  *  * \param index The zero-based index into the set of overloaded declarations in  * the cursor.  *  * \returns A cursor representing the declaration referenced by the given   * \c cursor at the specified \c index. If the cursor does not have an   * associated set of overloaded declarations, or if the index is out of bounds,  * returns \c clang_getNullCursor();  */
name|CINDEX_LINKAGE
name|CXCursor
name|clang_getOverloadedDecl
parameter_list|(
name|CXCursor
name|cursor
parameter_list|,
name|unsigned
name|index
parameter_list|)
function_decl|;
comment|/**  * @}  */
comment|/**  * \defgroup CINDEX_ATTRIBUTES Information for attributes  *  * @{  */
comment|/**  * \brief For cursors representing an iboutletcollection attribute,  *  this function returns the collection element type.  *  */
name|CINDEX_LINKAGE
name|CXType
name|clang_getIBOutletCollectionType
parameter_list|(
name|CXCursor
parameter_list|)
function_decl|;
comment|/**  * @}  */
comment|/**  * \defgroup CINDEX_CURSOR_TRAVERSAL Traversing the AST with cursors  *  * These routines provide the ability to traverse the abstract syntax tree  * using cursors.  *  * @{  */
comment|/**  * \brief Describes how the traversal of the children of a particular  * cursor should proceed after visiting a particular child cursor.  *  * A value of this enumeration type should be returned by each  * \c CXCursorVisitor to indicate how clang_visitChildren() proceed.  */
enum|enum
name|CXChildVisitResult
block|{
comment|/**    * \brief Terminates the cursor traversal.    */
name|CXChildVisit_Break
block|,
comment|/**    * \brief Continues the cursor traversal with the next sibling of    * the cursor just visited, without visiting its children.    */
name|CXChildVisit_Continue
block|,
comment|/**    * \brief Recursively traverse the children of this cursor, using    * the same visitor and client data.    */
name|CXChildVisit_Recurse
block|}
enum|;
comment|/**  * \brief Visitor invoked for each cursor found by a traversal.  *  * This visitor function will be invoked for each cursor found by  * clang_visitCursorChildren(). Its first argument is the cursor being  * visited, its second argument is the parent visitor for that cursor,  * and its third argument is the client data provided to  * clang_visitCursorChildren().  *  * The visitor should return one of the \c CXChildVisitResult values  * to direct clang_visitCursorChildren().  */
typedef|typedef
name|enum
name|CXChildVisitResult
function_decl|(
modifier|*
name|CXCursorVisitor
function_decl|)
parameter_list|(
name|CXCursor
name|cursor
parameter_list|,
name|CXCursor
name|parent
parameter_list|,
name|CXClientData
name|client_data
parameter_list|)
function_decl|;
comment|/**  * \brief Visit the children of a particular cursor.  *  * This function visits all the direct children of the given cursor,  * invoking the given \p visitor function with the cursors of each  * visited child. The traversal may be recursive, if the visitor returns  * \c CXChildVisit_Recurse. The traversal may also be ended prematurely, if  * the visitor returns \c CXChildVisit_Break.  *  * \param parent the cursor whose child may be visited. All kinds of  * cursors can be visited, including invalid cursors (which, by  * definition, have no children).  *  * \param visitor the visitor function that will be invoked for each  * child of \p parent.  *  * \param client_data pointer data supplied by the client, which will  * be passed to the visitor each time it is invoked.  *  * \returns a non-zero value if the traversal was terminated  * prematurely by the visitor returning \c CXChildVisit_Break.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_visitChildren
parameter_list|(
name|CXCursor
name|parent
parameter_list|,
name|CXCursorVisitor
name|visitor
parameter_list|,
name|CXClientData
name|client_data
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__has_feature
if|#
directive|if
name|__has_feature
argument_list|(
name|blocks
argument_list|)
comment|/**  * \brief Visitor invoked for each cursor found by a traversal.  *  * This visitor block will be invoked for each cursor found by  * clang_visitChildrenWithBlock(). Its first argument is the cursor being  * visited, its second argument is the parent visitor for that cursor.  *  * The visitor should return one of the \c CXChildVisitResult values  * to direct clang_visitChildrenWithBlock().  */
typedef|typedef
name|enum
name|CXChildVisitResult
function_decl|(
modifier|^
name|CXCursorVisitorBlock
function_decl|)
parameter_list|(
name|CXCursor
name|cursor
parameter_list|,
name|CXCursor
name|parent
parameter_list|)
function_decl|;
comment|/**  * Visits the children of a cursor using the specified block.  Behaves  * identically to clang_visitChildren() in all other respects.  */
name|unsigned
name|clang_visitChildrenWithBlock
parameter_list|(
name|CXCursor
name|parent
parameter_list|,
name|CXCursorVisitorBlock
name|block
parameter_list|)
function_decl|;
endif|#
directive|endif
endif|#
directive|endif
comment|/**  * @}  */
comment|/**  * \defgroup CINDEX_CURSOR_XREF Cross-referencing in the AST  *  * These routines provide the ability to determine references within and  * across translation units, by providing the names of the entities referenced  * by cursors, follow reference cursors to the declarations they reference,  * and associate declarations with their definitions.  *  * @{  */
comment|/**  * \brief Retrieve a Unified Symbol Resolution (USR) for the entity referenced  * by the given cursor.  *  * A Unified Symbol Resolution (USR) is a string that identifies a particular  * entity (function, class, variable, etc.) within a program. USRs can be  * compared across translation units to determine, e.g., when references in  * one translation refer to an entity defined in another translation unit.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_getCursorUSR
parameter_list|(
name|CXCursor
parameter_list|)
function_decl|;
comment|/**  * \brief Construct a USR for a specified Objective-C class.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_constructUSR_ObjCClass
parameter_list|(
specifier|const
name|char
modifier|*
name|class_name
parameter_list|)
function_decl|;
comment|/**  * \brief Construct a USR for a specified Objective-C category.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_constructUSR_ObjCCategory
parameter_list|(
specifier|const
name|char
modifier|*
name|class_name
parameter_list|,
specifier|const
name|char
modifier|*
name|category_name
parameter_list|)
function_decl|;
comment|/**  * \brief Construct a USR for a specified Objective-C protocol.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_constructUSR_ObjCProtocol
parameter_list|(
specifier|const
name|char
modifier|*
name|protocol_name
parameter_list|)
function_decl|;
comment|/**  * \brief Construct a USR for a specified Objective-C instance variable and  *   the USR for its containing class.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_constructUSR_ObjCIvar
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|CXString
name|classUSR
parameter_list|)
function_decl|;
comment|/**  * \brief Construct a USR for a specified Objective-C method and  *   the USR for its containing class.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_constructUSR_ObjCMethod
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|unsigned
name|isInstanceMethod
parameter_list|,
name|CXString
name|classUSR
parameter_list|)
function_decl|;
comment|/**  * \brief Construct a USR for a specified Objective-C property and the USR  *  for its containing class.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_constructUSR_ObjCProperty
parameter_list|(
specifier|const
name|char
modifier|*
name|property
parameter_list|,
name|CXString
name|classUSR
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve a name for the entity referenced by this cursor.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_getCursorSpelling
parameter_list|(
name|CXCursor
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the display name for the entity referenced by this cursor.  *  * The display name contains extra information that helps identify the cursor,  * such as the parameters of a function or template or the arguments of a   * class template specialization.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_getCursorDisplayName
parameter_list|(
name|CXCursor
parameter_list|)
function_decl|;
comment|/** \brief For a cursor that is a reference, retrieve a cursor representing the  * entity that it references.  *  * Reference cursors refer to other entities in the AST. For example, an  * Objective-C superclass reference cursor refers to an Objective-C class.  * This function produces the cursor for the Objective-C class from the  * cursor for the superclass reference. If the input cursor is a declaration or  * definition, it returns that declaration or definition unchanged.  * Otherwise, returns the NULL cursor.  */
name|CINDEX_LINKAGE
name|CXCursor
name|clang_getCursorReferenced
parameter_list|(
name|CXCursor
parameter_list|)
function_decl|;
comment|/**  *  \brief For a cursor that is either a reference to or a declaration  *  of some entity, retrieve a cursor that describes the definition of  *  that entity.  *  *  Some entities can be declared multiple times within a translation  *  unit, but only one of those declarations can also be a  *  definition. For example, given:  *  *  \code  *  int f(int, int);  *  int g(int x, int y) { return f(x, y); }  *  int f(int a, int b) { return a + b; }  *  int f(int, int);  *  \endcode  *  *  there are three declarations of the function "f", but only the  *  second one is a definition. The clang_getCursorDefinition()  *  function will take any cursor pointing to a declaration of "f"  *  (the first or fourth lines of the example) or a cursor referenced  *  that uses "f" (the call to "f' inside "g") and will return a  *  declaration cursor pointing to the definition (the second "f"  *  declaration).  *  *  If given a cursor for which there is no corresponding definition,  *  e.g., because there is no definition of that entity within this  *  translation unit, returns a NULL cursor.  */
name|CINDEX_LINKAGE
name|CXCursor
name|clang_getCursorDefinition
parameter_list|(
name|CXCursor
parameter_list|)
function_decl|;
comment|/**  * \brief Determine whether the declaration pointed to by this cursor  * is also a definition of that entity.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_isCursorDefinition
parameter_list|(
name|CXCursor
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the canonical cursor corresponding to the given cursor.  *  * In the C family of languages, many kinds of entities can be declared several  * times within a single translation unit. For example, a structure type can  * be forward-declared (possibly multiple times) and later defined:  *  * \code  * struct X;  * struct X;  * struct X {  *   int member;  * };  * \endcode  *  * The declarations and the definition of \c X are represented by three   * different cursors, all of which are declarations of the same underlying   * entity. One of these cursor is considered the "canonical" cursor, which  * is effectively the representative for the underlying entity. One can   * determine if two cursors are declarations of the same underlying entity by  * comparing their canonical cursors.  *  * \returns The canonical cursor for the entity referred to by the given cursor.  */
name|CINDEX_LINKAGE
name|CXCursor
name|clang_getCanonicalCursor
parameter_list|(
name|CXCursor
parameter_list|)
function_decl|;
comment|/**  * @}  */
comment|/**  * \defgroup CINDEX_CPP C++ AST introspection  *  * The routines in this group provide access information in the ASTs specific  * to C++ language features.  *  * @{  */
comment|/**  * \brief Determine if a C++ member function or member function template is   * declared 'static'.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_CXXMethod_isStatic
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * \brief Given a cursor that represents a template, determine  * the cursor kind of the specializations would be generated by instantiating  * the template.  *  * This routine can be used to determine what flavor of function template,  * class template, or class template partial specialization is stored in the  * cursor. For example, it can describe whether a class template cursor is  * declared with "struct", "class" or "union".  *  * \param C The cursor to query. This cursor should represent a template  * declaration.  *  * \returns The cursor kind of the specializations that would be generated  * by instantiating the template \p C. If \p C is not a template, returns  * \c CXCursor_NoDeclFound.  */
name|CINDEX_LINKAGE
name|enum
name|CXCursorKind
name|clang_getTemplateCursorKind
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * \brief Given a cursor that may represent a specialization or instantiation  * of a template, retrieve the cursor that represents the template that it  * specializes or from which it was instantiated.  *  * This routine determines the template involved both for explicit   * specializations of templates and for implicit instantiations of the template,  * both of which are referred to as "specializations". For a class template  * specialization (e.g., \c std::vector<bool>), this routine will return   * either the primary template (\c std::vector) or, if the specialization was  * instantiated from a class template partial specialization, the class template  * partial specialization. For a class template partial specialization and a  * function template specialization (including instantiations), this  * this routine will return the specialized template.  *  * For members of a class template (e.g., member functions, member classes, or  * static data members), returns the specialized or instantiated member.   * Although not strictly "templates" in the C++ language, members of class  * templates have the same notions of specializations and instantiations that  * templates do, so this routine treats them similarly.  *  * \param C A cursor that may be a specialization of a template or a member  * of a template.  *  * \returns If the given cursor is a specialization or instantiation of a   * template or a member thereof, the template or member that it specializes or  * from which it was instantiated. Otherwise, returns a NULL cursor.  */
name|CINDEX_LINKAGE
name|CXCursor
name|clang_getSpecializedCursorTemplate
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * @}  */
comment|/**  * \defgroup CINDEX_LEX Token extraction and manipulation  *  * The routines in this group provide access to the tokens within a  * translation unit, along with a semantic mapping of those tokens to  * their corresponding cursors.  *  * @{  */
comment|/**  * \brief Describes a kind of token.  */
typedef|typedef
enum|enum
name|CXTokenKind
block|{
comment|/**    * \brief A token that contains some kind of punctuation.    */
name|CXToken_Punctuation
block|,
comment|/**    * \brief A language keyword.    */
name|CXToken_Keyword
block|,
comment|/**    * \brief An identifier (that is not a keyword).    */
name|CXToken_Identifier
block|,
comment|/**    * \brief A numeric, string, or character literal.    */
name|CXToken_Literal
block|,
comment|/**    * \brief A comment.    */
name|CXToken_Comment
block|}
name|CXTokenKind
typedef|;
comment|/**  * \brief Describes a single preprocessing token.  */
typedef|typedef
struct|struct
block|{
name|unsigned
name|int_data
index|[
literal|4
index|]
decl_stmt|;
name|void
modifier|*
name|ptr_data
decl_stmt|;
block|}
name|CXToken
typedef|;
comment|/**  * \brief Determine the kind of the given token.  */
name|CINDEX_LINKAGE
name|CXTokenKind
name|clang_getTokenKind
parameter_list|(
name|CXToken
parameter_list|)
function_decl|;
comment|/**  * \brief Determine the spelling of the given token.  *  * The spelling of a token is the textual representation of that token, e.g.,  * the text of an identifier or keyword.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_getTokenSpelling
parameter_list|(
name|CXTranslationUnit
parameter_list|,
name|CXToken
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the source location of the given token.  */
name|CINDEX_LINKAGE
name|CXSourceLocation
name|clang_getTokenLocation
parameter_list|(
name|CXTranslationUnit
parameter_list|,
name|CXToken
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve a source range that covers the given token.  */
name|CINDEX_LINKAGE
name|CXSourceRange
name|clang_getTokenExtent
parameter_list|(
name|CXTranslationUnit
parameter_list|,
name|CXToken
parameter_list|)
function_decl|;
comment|/**  * \brief Tokenize the source code described by the given range into raw  * lexical tokens.  *  * \param TU the translation unit whose text is being tokenized.  *  * \param Range the source range in which text should be tokenized. All of the  * tokens produced by tokenization will fall within this source range,  *  * \param Tokens this pointer will be set to point to the array of tokens  * that occur within the given source range. The returned pointer must be  * freed with clang_disposeTokens() before the translation unit is destroyed.  *  * \param NumTokens will be set to the number of tokens in the \c *Tokens  * array.  *  */
name|CINDEX_LINKAGE
name|void
name|clang_tokenize
parameter_list|(
name|CXTranslationUnit
name|TU
parameter_list|,
name|CXSourceRange
name|Range
parameter_list|,
name|CXToken
modifier|*
modifier|*
name|Tokens
parameter_list|,
name|unsigned
modifier|*
name|NumTokens
parameter_list|)
function_decl|;
comment|/**  * \brief Annotate the given set of tokens by providing cursors for each token  * that can be mapped to a specific entity within the abstract syntax tree.  *  * This token-annotation routine is equivalent to invoking  * clang_getCursor() for the source locations of each of the  * tokens. The cursors provided are filtered, so that only those  * cursors that have a direct correspondence to the token are  * accepted. For example, given a function call \c f(x),  * clang_getCursor() would provide the following cursors:  *  *   * when the cursor is over the 'f', a DeclRefExpr cursor referring to 'f'.  *   * when the cursor is over the '(' or the ')', a CallExpr referring to 'f'.  *   * when the cursor is over the 'x', a DeclRefExpr cursor referring to 'x'.  *  * Only the first and last of these cursors will occur within the  * annotate, since the tokens "f" and "x' directly refer to a function  * and a variable, respectively, but the parentheses are just a small  * part of the full syntax of the function call expression, which is  * not provided as an annotation.  *  * \param TU the translation unit that owns the given tokens.  *  * \param Tokens the set of tokens to annotate.  *  * \param NumTokens the number of tokens in \p Tokens.  *  * \param Cursors an array of \p NumTokens cursors, whose contents will be  * replaced with the cursors corresponding to each token.  */
name|CINDEX_LINKAGE
name|void
name|clang_annotateTokens
parameter_list|(
name|CXTranslationUnit
name|TU
parameter_list|,
name|CXToken
modifier|*
name|Tokens
parameter_list|,
name|unsigned
name|NumTokens
parameter_list|,
name|CXCursor
modifier|*
name|Cursors
parameter_list|)
function_decl|;
comment|/**  * \brief Free the given set of tokens.  */
name|CINDEX_LINKAGE
name|void
name|clang_disposeTokens
parameter_list|(
name|CXTranslationUnit
name|TU
parameter_list|,
name|CXToken
modifier|*
name|Tokens
parameter_list|,
name|unsigned
name|NumTokens
parameter_list|)
function_decl|;
comment|/**  * @}  */
comment|/**  * \defgroup CINDEX_DEBUG Debugging facilities  *  * These routines are used for testing and debugging, only, and should not  * be relied upon.  *  * @{  */
comment|/* for debug/testing */
name|CINDEX_LINKAGE
name|CXString
name|clang_getCursorKindSpelling
parameter_list|(
name|enum
name|CXCursorKind
name|Kind
parameter_list|)
function_decl|;
name|CINDEX_LINKAGE
name|void
name|clang_getDefinitionSpellingAndExtent
parameter_list|(
name|CXCursor
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|startBuf
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|endBuf
parameter_list|,
name|unsigned
modifier|*
name|startLine
parameter_list|,
name|unsigned
modifier|*
name|startColumn
parameter_list|,
name|unsigned
modifier|*
name|endLine
parameter_list|,
name|unsigned
modifier|*
name|endColumn
parameter_list|)
function_decl|;
name|CINDEX_LINKAGE
name|void
name|clang_enableStackTraces
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|CINDEX_LINKAGE
name|void
name|clang_executeOnThread
parameter_list|(
name|void
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|,
name|unsigned
name|stack_size
parameter_list|)
function_decl|;
comment|/**  * @}  */
comment|/**  * \defgroup CINDEX_CODE_COMPLET Code completion  *  * Code completion involves taking an (incomplete) source file, along with  * knowledge of where the user is actively editing that file, and suggesting  * syntactically- and semantically-valid constructs that the user might want to  * use at that particular point in the source code. These data structures and  * routines provide support for code completion.  *  * @{  */
comment|/**  * \brief A semantic string that describes a code-completion result.  *  * A semantic string that describes the formatting of a code-completion  * result as a single "template" of text that should be inserted into the  * source buffer when a particular code-completion result is selected.  * Each semantic string is made up of some number of "chunks", each of which  * contains some text along with a description of what that text means, e.g.,  * the name of the entity being referenced, whether the text chunk is part of  * the template, or whether it is a "placeholder" that the user should replace  * with actual code,of a specific kind. See \c CXCompletionChunkKind for a  * description of the different kinds of chunks.  */
typedef|typedef
name|void
modifier|*
name|CXCompletionString
typedef|;
comment|/**  * \brief A single result of code completion.  */
typedef|typedef
struct|struct
block|{
comment|/**    * \brief The kind of entity that this completion refers to.    *    * The cursor kind will be a macro, keyword, or a declaration (one of the    * *Decl cursor kinds), describing the entity that the completion is    * referring to.    *    * \todo In the future, we would like to provide a full cursor, to allow    * the client to extract additional information from declaration.    */
name|enum
name|CXCursorKind
name|CursorKind
decl_stmt|;
comment|/**    * \brief The code-completion string that describes how to insert this    * code-completion result into the editing buffer.    */
name|CXCompletionString
name|CompletionString
decl_stmt|;
block|}
name|CXCompletionResult
typedef|;
comment|/**  * \brief Describes a single piece of text within a code-completion string.  *  * Each "chunk" within a code-completion string (\c CXCompletionString) is  * either a piece of text with a specific "kind" that describes how that text  * should be interpreted by the client or is another completion string.  */
enum|enum
name|CXCompletionChunkKind
block|{
comment|/**    * \brief A code-completion string that describes "optional" text that    * could be a part of the template (but is not required).    *    * The Optional chunk is the only kind of chunk that has a code-completion    * string for its representation, which is accessible via    * \c clang_getCompletionChunkCompletionString(). The code-completion string    * describes an additional part of the template that is completely optional.    * For example, optional chunks can be used to describe the placeholders for    * arguments that match up with defaulted function parameters, e.g. given:    *    * \code    * void f(int x, float y = 3.14, double z = 2.71828);    * \endcode    *    * The code-completion string for this function would contain:    *   - a TypedText chunk for "f".    *   - a LeftParen chunk for "(".    *   - a Placeholder chunk for "int x"    *   - an Optional chunk containing the remaining defaulted arguments, e.g.,    *       - a Comma chunk for ","    *       - a Placeholder chunk for "float y"    *       - an Optional chunk containing the last defaulted argument:    *           - a Comma chunk for ","    *           - a Placeholder chunk for "double z"    *   - a RightParen chunk for ")"    *    * There are many ways to handle Optional chunks. Two simple approaches are:    *   - Completely ignore optional chunks, in which case the template for the    *     function "f" would only include the first parameter ("int x").    *   - Fully expand all optional chunks, in which case the template for the    *     function "f" would have all of the parameters.    */
name|CXCompletionChunk_Optional
block|,
comment|/**    * \brief Text that a user would be expected to type to get this    * code-completion result.    *    * There will be exactly one "typed text" chunk in a semantic string, which    * will typically provide the spelling of a keyword or the name of a    * declaration that could be used at the current code point. Clients are    * expected to filter the code-completion results based on the text in this    * chunk.    */
name|CXCompletionChunk_TypedText
block|,
comment|/**    * \brief Text that should be inserted as part of a code-completion result.    *    * A "text" chunk represents text that is part of the template to be    * inserted into user code should this particular code-completion result    * be selected.    */
name|CXCompletionChunk_Text
block|,
comment|/**    * \brief Placeholder text that should be replaced by the user.    *    * A "placeholder" chunk marks a place where the user should insert text    * into the code-completion template. For example, placeholders might mark    * the function parameters for a function declaration, to indicate that the    * user should provide arguments for each of those parameters. The actual    * text in a placeholder is a suggestion for the text to display before    * the user replaces the placeholder with real code.    */
name|CXCompletionChunk_Placeholder
block|,
comment|/**    * \brief Informative text that should be displayed but never inserted as    * part of the template.    *    * An "informative" chunk contains annotations that can be displayed to    * help the user decide whether a particular code-completion result is the    * right option, but which is not part of the actual template to be inserted    * by code completion.    */
name|CXCompletionChunk_Informative
block|,
comment|/**    * \brief Text that describes the current parameter when code-completion is    * referring to function call, message send, or template specialization.    *    * A "current parameter" chunk occurs when code-completion is providing    * information about a parameter corresponding to the argument at the    * code-completion point. For example, given a function    *    * \code    * int add(int x, int y);    * \endcode    *    * and the source code \c add(, where the code-completion point is after the    * "(", the code-completion string will contain a "current parameter" chunk    * for "int x", indicating that the current argument will initialize that    * parameter. After typing further, to \c add(17, (where the code-completion    * point is after the ","), the code-completion string will contain a    * "current paremeter" chunk to "int y".    */
name|CXCompletionChunk_CurrentParameter
block|,
comment|/**    * \brief A left parenthesis ('('), used to initiate a function call or    * signal the beginning of a function parameter list.    */
name|CXCompletionChunk_LeftParen
block|,
comment|/**    * \brief A right parenthesis (')'), used to finish a function call or    * signal the end of a function parameter list.    */
name|CXCompletionChunk_RightParen
block|,
comment|/**    * \brief A left bracket ('[').    */
name|CXCompletionChunk_LeftBracket
block|,
comment|/**    * \brief A right bracket (']').    */
name|CXCompletionChunk_RightBracket
block|,
comment|/**    * \brief A left brace ('{').    */
name|CXCompletionChunk_LeftBrace
block|,
comment|/**    * \brief A right brace ('}').    */
name|CXCompletionChunk_RightBrace
block|,
comment|/**    * \brief A left angle bracket ('<').    */
name|CXCompletionChunk_LeftAngle
block|,
comment|/**    * \brief A right angle bracket ('>').    */
name|CXCompletionChunk_RightAngle
block|,
comment|/**    * \brief A comma separator (',').    */
name|CXCompletionChunk_Comma
block|,
comment|/**    * \brief Text that specifies the result type of a given result.    *    * This special kind of informative chunk is not meant to be inserted into    * the text buffer. Rather, it is meant to illustrate the type that an    * expression using the given completion string would have.    */
name|CXCompletionChunk_ResultType
block|,
comment|/**    * \brief A colon (':').    */
name|CXCompletionChunk_Colon
block|,
comment|/**    * \brief A semicolon (';').    */
name|CXCompletionChunk_SemiColon
block|,
comment|/**    * \brief An '=' sign.    */
name|CXCompletionChunk_Equal
block|,
comment|/**    * Horizontal space (' ').    */
name|CXCompletionChunk_HorizontalSpace
block|,
comment|/**    * Vertical space ('\n'), after which it is generally a good idea to    * perform indentation.    */
name|CXCompletionChunk_VerticalSpace
block|}
enum|;
comment|/**  * \brief Determine the kind of a particular chunk within a completion string.  *  * \param completion_string the completion string to query.  *  * \param chunk_number the 0-based index of the chunk in the completion string.  *  * \returns the kind of the chunk at the index \c chunk_number.  */
name|CINDEX_LINKAGE
name|enum
name|CXCompletionChunkKind
name|clang_getCompletionChunkKind
parameter_list|(
name|CXCompletionString
name|completion_string
parameter_list|,
name|unsigned
name|chunk_number
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the text associated with a particular chunk within a  * completion string.  *  * \param completion_string the completion string to query.  *  * \param chunk_number the 0-based index of the chunk in the completion string.  *  * \returns the text associated with the chunk at index \c chunk_number.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_getCompletionChunkText
parameter_list|(
name|CXCompletionString
name|completion_string
parameter_list|,
name|unsigned
name|chunk_number
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the completion string associated with a particular chunk  * within a completion string.  *  * \param completion_string the completion string to query.  *  * \param chunk_number the 0-based index of the chunk in the completion string.  *  * \returns the completion string associated with the chunk at index  * \c chunk_number, or NULL if that chunk is not represented by a completion  * string.  */
name|CINDEX_LINKAGE
name|CXCompletionString
name|clang_getCompletionChunkCompletionString
parameter_list|(
name|CXCompletionString
name|completion_string
parameter_list|,
name|unsigned
name|chunk_number
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the number of chunks in the given code-completion string.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_getNumCompletionChunks
parameter_list|(
name|CXCompletionString
name|completion_string
parameter_list|)
function_decl|;
comment|/**  * \brief Determine the priority of this code completion.  *  * The priority of a code completion indicates how likely it is that this   * particular completion is the completion that the user will select. The  * priority is selected by various internal heuristics.  *  * \param completion_string The completion string to query.  *  * \returns The priority of this completion string. Smaller values indicate  * higher-priority (more likely) completions.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_getCompletionPriority
parameter_list|(
name|CXCompletionString
name|completion_string
parameter_list|)
function_decl|;
comment|/**  * \brief Determine the availability of the entity that this code-completion  * string refers to.  *  * \param completion_string The completion string to query.  *  * \returns The availability of the completion string.  */
name|CINDEX_LINKAGE
name|enum
name|CXAvailabilityKind
name|clang_getCompletionAvailability
parameter_list|(
name|CXCompletionString
name|completion_string
parameter_list|)
function_decl|;
comment|/**  * \brief Contains the results of code-completion.  *  * This data structure contains the results of code completion, as  * produced by \c clang_codeCompleteAt(). Its contents must be freed by  * \c clang_disposeCodeCompleteResults.  */
typedef|typedef
struct|struct
block|{
comment|/**    * \brief The code-completion results.    */
name|CXCompletionResult
modifier|*
name|Results
decl_stmt|;
comment|/**    * \brief The number of code-completion results stored in the    * \c Results array.    */
name|unsigned
name|NumResults
decl_stmt|;
block|}
name|CXCodeCompleteResults
typedef|;
comment|/**  * \brief Flags that can be passed to \c clang_codeCompleteAt() to  * modify its behavior.  *  * The enumerators in this enumeration can be bitwise-OR'd together to  * provide multiple options to \c clang_codeCompleteAt().  */
enum|enum
name|CXCodeComplete_Flags
block|{
comment|/**    * \brief Whether to include macros within the set of code    * completions returned.    */
name|CXCodeComplete_IncludeMacros
init|=
literal|0x01
block|,
comment|/**    * \brief Whether to include code patterns for language constructs    * within the set of code completions, e.g., for loops.    */
name|CXCodeComplete_IncludeCodePatterns
init|=
literal|0x02
block|}
enum|;
comment|/**  * \brief Returns a default set of code-completion options that can be  * passed to\c clang_codeCompleteAt().   */
name|CINDEX_LINKAGE
name|unsigned
name|clang_defaultCodeCompleteOptions
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * \brief Perform code completion at a given location in a translation unit.  *  * This function performs code completion at a particular file, line, and  * column within source code, providing results that suggest potential  * code snippets based on the context of the completion. The basic model  * for code completion is that Clang will parse a complete source file,  * performing syntax checking up to the location where code-completion has  * been requested. At that point, a special code-completion token is passed  * to the parser, which recognizes this token and determines, based on the  * current location in the C/Objective-C/C++ grammar and the state of  * semantic analysis, what completions to provide. These completions are  * returned via a new \c CXCodeCompleteResults structure.  *  * Code completion itself is meant to be triggered by the client when the  * user types punctuation characters or whitespace, at which point the  * code-completion location will coincide with the cursor. For example, if \c p  * is a pointer, code-completion might be triggered after the "-" and then  * after the ">" in \c p->. When the code-completion location is afer the ">",  * the completion results will provide, e.g., the members of the struct that  * "p" points to. The client is responsible for placing the cursor at the  * beginning of the token currently being typed, then filtering the results  * based on the contents of the token. For example, when code-completing for  * the expression \c p->get, the client should provide the location just after  * the ">" (e.g., pointing at the "g") to this code-completion hook. Then, the  * client can filter the results based on the current token text ("get"), only  * showing those results that start with "get". The intent of this interface  * is to separate the relatively high-latency acquisition of code-completion  * results from the filtering of results on a per-character basis, which must  * have a lower latency.  *  * \param TU The translation unit in which code-completion should  * occur. The source files for this translation unit need not be  * completely up-to-date (and the contents of those source files may  * be overridden via \p unsaved_files). Cursors referring into the  * translation unit may be invalidated by this invocation.  *  * \param complete_filename The name of the source file where code  * completion should be performed. This filename may be any file  * included in the translation unit.  *  * \param complete_line The line at which code-completion should occur.  *  * \param complete_column The column at which code-completion should occur.  * Note that the column should point just after the syntactic construct that  * initiated code completion, and not in the middle of a lexical token.  *  * \param unsaved_files the Tiles that have not yet been saved to disk  * but may be required for parsing or code completion, including the  * contents of those files.  The contents and name of these files (as  * specified by CXUnsavedFile) are copied when necessary, so the  * client only needs to guarantee their validity until the call to  * this function returns.  *  * \param num_unsaved_files The number of unsaved file entries in \p  * unsaved_files.  *  * \param options Extra options that control the behavior of code  * completion, expressed as a bitwise OR of the enumerators of the  * CXCodeComplete_Flags enumeration. The   * \c clang_defaultCodeCompleteOptions() function returns a default set  * of code-completion options.  *  * \returns If successful, a new \c CXCodeCompleteResults structure  * containing code-completion results, which should eventually be  * freed with \c clang_disposeCodeCompleteResults(). If code  * completion fails, returns NULL.  */
name|CINDEX_LINKAGE
name|CXCodeCompleteResults
modifier|*
name|clang_codeCompleteAt
parameter_list|(
name|CXTranslationUnit
name|TU
parameter_list|,
specifier|const
name|char
modifier|*
name|complete_filename
parameter_list|,
name|unsigned
name|complete_line
parameter_list|,
name|unsigned
name|complete_column
parameter_list|,
name|struct
name|CXUnsavedFile
modifier|*
name|unsaved_files
parameter_list|,
name|unsigned
name|num_unsaved_files
parameter_list|,
name|unsigned
name|options
parameter_list|)
function_decl|;
comment|/**  * \brief Sort the code-completion results in case-insensitive alphabetical   * order.  *  * \param Results The set of results to sort.  * \param NumResults The number of results in \p Results.  */
name|CINDEX_LINKAGE
name|void
name|clang_sortCodeCompletionResults
parameter_list|(
name|CXCompletionResult
modifier|*
name|Results
parameter_list|,
name|unsigned
name|NumResults
parameter_list|)
function_decl|;
comment|/**  * \brief Free the given set of code-completion results.  */
name|CINDEX_LINKAGE
name|void
name|clang_disposeCodeCompleteResults
parameter_list|(
name|CXCodeCompleteResults
modifier|*
name|Results
parameter_list|)
function_decl|;
comment|/**  * \brief Determine the number of diagnostics produced prior to the  * location where code completion was performed.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_codeCompleteGetNumDiagnostics
parameter_list|(
name|CXCodeCompleteResults
modifier|*
name|Results
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve a diagnostic associated with the given code completion.  *  * \param Result the code completion results to query.  * \param Index the zero-based diagnostic number to retrieve.  *  * \returns the requested diagnostic. This diagnostic must be freed  * via a call to \c clang_disposeDiagnostic().  */
name|CINDEX_LINKAGE
name|CXDiagnostic
name|clang_codeCompleteGetDiagnostic
parameter_list|(
name|CXCodeCompleteResults
modifier|*
name|Results
parameter_list|,
name|unsigned
name|Index
parameter_list|)
function_decl|;
comment|/**  * @}  */
comment|/**  * \defgroup CINDEX_MISC Miscellaneous utility functions  *  * @{  */
comment|/**  * \brief Return a version string, suitable for showing to a user, but not  *        intended to be parsed (the format is not guaranteed to be stable).  */
name|CINDEX_LINKAGE
name|CXString
name|clang_getClangVersion
parameter_list|()
function_decl|;
comment|/**   * \brief Visitor invoked for each file in a translation unit   *        (used with clang_getInclusions()).   *   * This visitor function will be invoked by clang_getInclusions() for each   * file included (either at the top-level or by #include directives) within   * a translation unit.  The first argument is the file being included, and   * the second and third arguments provide the inclusion stack.  The   * array is sorted in order of immediate inclusion.  For example,   * the first element refers to the location that included 'included_file'.   */
typedef|typedef
name|void
function_decl|(
modifier|*
name|CXInclusionVisitor
function_decl|)
parameter_list|(
name|CXFile
name|included_file
parameter_list|,
name|CXSourceLocation
modifier|*
name|inclusion_stack
parameter_list|,
name|unsigned
name|include_len
parameter_list|,
name|CXClientData
name|client_data
parameter_list|)
function_decl|;
comment|/**  * \brief Visit the set of preprocessor inclusions in a translation unit.  *   The visitor function is called with the provided data for every included  *   file.  This does not include headers included by the PCH file (unless one  *   is inspecting the inclusions in the PCH file itself).  */
name|CINDEX_LINKAGE
name|void
name|clang_getInclusions
parameter_list|(
name|CXTranslationUnit
name|tu
parameter_list|,
name|CXInclusionVisitor
name|visitor
parameter_list|,
name|CXClientData
name|client_data
parameter_list|)
function_decl|;
comment|/**  * @}  */
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

end_unit

