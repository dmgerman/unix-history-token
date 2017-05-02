begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===-- clang-c/Index.h - Indexing Public C Interface -------------*- C -*-===*\ |*                                                                            *| |*                     The LLVM Compiler Infrastructure                       *| |*                                                                            *| |* This file is distributed under the University of Illinois Open Source      *| |* License. See LICENSE.TXT for details.                                      *| |*                                                                            *| |*===----------------------------------------------------------------------===*| |*                                                                            *| |* This header provides a public inferface to a Clang library for extracting  *| |* high-level symbol information from source files without exposing the full  *| |* Clang C++ API.                                                             *| |*                                                                            *| \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_C_INDEX_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_C_INDEX_H
end_define

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|"clang-c/Platform.h"
end_include

begin_include
include|#
directive|include
file|"clang-c/CXErrorCode.h"
end_include

begin_include
include|#
directive|include
file|"clang-c/CXString.h"
end_include

begin_include
include|#
directive|include
file|"clang-c/BuildSystem.h"
end_include

begin_comment
comment|/**  * \brief The version constants for the libclang API.  * CINDEX_VERSION_MINOR should increase when there are API additions.  * CINDEX_VERSION_MAJOR is intended for "major" source/ABI breaking changes.  *  * The policy about the libclang API was always to keep it source and ABI  * compatible, thus CINDEX_VERSION_MAJOR is expected to remain stable.  */
end_comment

begin_define
define|#
directive|define
name|CINDEX_VERSION_MAJOR
value|0
end_define

begin_define
define|#
directive|define
name|CINDEX_VERSION_MINOR
value|38
end_define

begin_define
define|#
directive|define
name|CINDEX_VERSION_ENCODE
parameter_list|(
name|major
parameter_list|,
name|minor
parameter_list|)
value|( \       ((major) * 10000)                       \     + ((minor) *     1))
end_define

begin_define
define|#
directive|define
name|CINDEX_VERSION
value|CINDEX_VERSION_ENCODE( \     CINDEX_VERSION_MAJOR,                     \     CINDEX_VERSION_MINOR )
end_define

begin_define
define|#
directive|define
name|CINDEX_VERSION_STRINGIZE_
parameter_list|(
name|major
parameter_list|,
name|minor
parameter_list|)
define|\
value|#major"."#minor
end_define

begin_define
define|#
directive|define
name|CINDEX_VERSION_STRINGIZE
parameter_list|(
name|major
parameter_list|,
name|minor
parameter_list|)
define|\
value|CINDEX_VERSION_STRINGIZE_(major, minor)
end_define

begin_define
define|#
directive|define
name|CINDEX_VERSION_STRING
value|CINDEX_VERSION_STRINGIZE( \     CINDEX_VERSION_MAJOR,                               \     CINDEX_VERSION_MINOR)
end_define

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
comment|/** \defgroup CINDEX libclang: C Interface to Clang  *  * The C Interface to Clang provides a relatively small API that exposes  * facilities for parsing source code into an abstract syntax tree (AST),  * loading already-parsed ASTs, traversing the AST, associating  * physical source locations with elements within the AST, and other  * facilities that support Clang-based development tools.  *  * This C interface to Clang will never provide all of the information  * representation stored in Clang's C++ AST, nor should it: the intent is to  * maintain an API that is relatively stable from one release to the next,  * providing only the basic functionality needed to support development tools.  *  * To avoid namespace pollution, data types are prefixed with "CX" and  * functions are prefixed with "clang_".  *  * @{  */
comment|/**  * \brief An "index" that consists of a set of translation units that would  * typically be linked together into an executable or library.  */
typedef|typedef
name|void
modifier|*
name|CXIndex
typedef|;
comment|/**  * \brief An opaque type representing target information for a given translation  * unit.  */
typedef|typedef
name|struct
name|CXTargetInfoImpl
modifier|*
name|CXTargetInfo
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
block|,
comment|/**    * \brief The entity is available, but not accessible; any use of it will be    * an error.    */
name|CXAvailability_NotAccessible
block|}
enum|;
comment|/**  * \brief Describes a version number of the form major.minor.subminor.  */
typedef|typedef
struct|struct
name|CXVersion
block|{
comment|/**    * \brief The major version number, e.g., the '10' in '10.7.3'. A negative    * value indicates that there is no version number at all.    */
name|int
name|Major
decl_stmt|;
comment|/**    * \brief The minor version number, e.g., the '7' in '10.7.3'. This value    * will be negative if no minor version number was provided, e.g., for     * version '10'.    */
name|int
name|Minor
decl_stmt|;
comment|/**    * \brief The subminor version number, e.g., the '3' in '10.7.3'. This value    * will be negative if no minor or subminor version number was provided,    * e.g., in version '10' or '10.7'.    */
name|int
name|Subminor
decl_stmt|;
block|}
name|CXVersion
typedef|;
comment|/**  * \brief Provides a shared context for creating translation units.  *  * It provides two options:  *  * - excludeDeclarationsFromPCH: When non-zero, allows enumeration of "local"  * declarations (when loading any new translation units). A "local" declaration  * is one that belongs in the translation unit itself and not in a precompiled  * header that was used by the translation unit. If zero, all declarations  * will be enumerated.  *  * Here is an example:  *  * \code  *   // excludeDeclsFromPCH = 1, displayDiagnostics=1  *   Idx = clang_createIndex(1, 1);  *  *   // IndexTest.pch was produced with the following command:  *   // "clang -x c IndexTest.h -emit-ast -o IndexTest.pch"  *   TU = clang_createTranslationUnit(Idx, "IndexTest.pch");  *  *   // This will load all the symbols from 'IndexTest.pch'  *   clang_visitChildren(clang_getTranslationUnitCursor(TU),  *                       TranslationUnitVisitor, 0);  *   clang_disposeTranslationUnit(TU);  *  *   // This will load all the symbols from 'IndexTest.c', excluding symbols  *   // from 'IndexTest.pch'.  *   char *args[] = { "-Xclang", "-include-pch=IndexTest.pch" };  *   TU = clang_createTranslationUnitFromSourceFile(Idx, "IndexTest.c", 2, args,  *                                                  0, 0);  *   clang_visitChildren(clang_getTranslationUnitCursor(TU),  *                       TranslationUnitVisitor, 0);  *   clang_disposeTranslationUnit(TU);  * \endcode  *  * This process of creating the 'pch', loading it separately, and using it (via  * -include-pch) allows 'excludeDeclsFromPCH' to remove redundant callbacks  * (which gives the indexer the same performance benefit as the compiler).  */
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
typedef|typedef
enum|enum
block|{
comment|/**    * \brief Used to indicate that no special CXIndex options are needed.    */
name|CXGlobalOpt_None
init|=
literal|0x0
block|,
comment|/**    * \brief Used to indicate that threads that libclang creates for indexing    * purposes should use background priority.    *    * Affects #clang_indexSourceFile, #clang_indexTranslationUnit,    * #clang_parseTranslationUnit, #clang_saveTranslationUnit.    */
name|CXGlobalOpt_ThreadBackgroundPriorityForIndexing
init|=
literal|0x1
block|,
comment|/**    * \brief Used to indicate that threads that libclang creates for editing    * purposes should use background priority.    *    * Affects #clang_reparseTranslationUnit, #clang_codeCompleteAt,    * #clang_annotateTokens    */
name|CXGlobalOpt_ThreadBackgroundPriorityForEditing
init|=
literal|0x2
block|,
comment|/**    * \brief Used to indicate that all threads that libclang creates should use    * background priority.    */
name|CXGlobalOpt_ThreadBackgroundPriorityForAll
init|=
name|CXGlobalOpt_ThreadBackgroundPriorityForIndexing
operator||
name|CXGlobalOpt_ThreadBackgroundPriorityForEditing
block|}
name|CXGlobalOptFlags
typedef|;
comment|/**  * \brief Sets general options associated with a CXIndex.  *  * For example:  * \code  * CXIndex idx = ...;  * clang_CXIndex_setGlobalOptions(idx,  *     clang_CXIndex_getGlobalOptions(idx) |  *     CXGlobalOpt_ThreadBackgroundPriorityForIndexing);  * \endcode  *  * \param options A bitmask of options, a bitwise OR of CXGlobalOpt_XXX flags.  */
name|CINDEX_LINKAGE
name|void
name|clang_CXIndex_setGlobalOptions
parameter_list|(
name|CXIndex
parameter_list|,
name|unsigned
name|options
parameter_list|)
function_decl|;
comment|/**  * \brief Gets the general options associated with a CXIndex.  *  * \returns A bitmask of options, a bitwise OR of CXGlobalOpt_XXX flags that  * are associated with the given CXIndex object.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_CXIndex_getGlobalOptions
parameter_list|(
name|CXIndex
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
comment|/**  * \brief Uniquely identifies a CXFile, that refers to the same underlying file,  * across an indexing session.  */
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|long
name|data
index|[
literal|3
index|]
decl_stmt|;
block|}
name|CXFileUniqueID
typedef|;
comment|/**  * \brief Retrieve the unique ID for the given \c file.  *  * \param file the file to get the ID for.  * \param outID stores the returned CXFileUniqueID.  * \returns If there was a failure getting the unique ID, returns non-zero,  * otherwise returns 0. */
name|CINDEX_LINKAGE
name|int
name|clang_getFileUniqueID
parameter_list|(
name|CXFile
name|file
parameter_list|,
name|CXFileUniqueID
modifier|*
name|outID
parameter_list|)
function_decl|;
comment|/**  * \brief Determine whether the given header is guarded against  * multiple inclusions, either with the conventional  * \#ifndef/\#define/\#endif macro guards or with \#pragma once.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_isFileMultipleIncludeGuarded
parameter_list|(
name|CXTranslationUnit
name|tu
parameter_list|,
name|CXFile
name|file
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
comment|/**  * \brief Returns non-zero if the \c file1 and \c file2 point to the same file,  * or they are both NULL.  */
name|CINDEX_LINKAGE
name|int
name|clang_File_isEqual
parameter_list|(
name|CXFile
name|file1
parameter_list|,
name|CXFile
name|file2
parameter_list|)
function_decl|;
comment|/**  * @}  */
comment|/**  * \defgroup CINDEX_LOCATIONS Physical source locations  *  * Clang represents physical source locations in its abstract syntax tree in  * great detail, with file, line, and column information for the majority of  * the tokens parsed in the source code. These data types and functions are  * used to represent source location information, either for a particular  * point in the program or for a range of points in the program, and extract  * specific location information from those data types.  *  * @{  */
comment|/**  * \brief Identifies a specific source location within a translation  * unit.  *  * Use clang_getExpansionLocation() or clang_getSpellingLocation()  * to map a source location to a particular file, line, and column.  */
typedef|typedef
struct|struct
block|{
specifier|const
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
specifier|const
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
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * \brief Determine whether two source locations, which must refer into  * the same translation unit, refer to exactly the same point in the source  * code.  *  * \returns non-zero if the source locations refer to the same location, zero  * if they refer to different locations.  */
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
comment|/**  * \brief Returns non-zero if the given source location is in a system header.  */
name|CINDEX_LINKAGE
name|int
name|clang_Location_isInSystemHeader
parameter_list|(
name|CXSourceLocation
name|location
parameter_list|)
function_decl|;
comment|/**  * \brief Returns non-zero if the given source location is in the main file of  * the corresponding translation unit.  */
name|CINDEX_LINKAGE
name|int
name|clang_Location_isFromMainFile
parameter_list|(
name|CXSourceLocation
name|location
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve a NULL (invalid) source range.  */
name|CINDEX_LINKAGE
name|CXSourceRange
name|clang_getNullRange
parameter_list|(
name|void
parameter_list|)
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
comment|/**  * \brief Determine whether two ranges are equivalent.  *  * \returns non-zero if the ranges are the same, zero if they differ.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_equalRanges
parameter_list|(
name|CXSourceRange
name|range1
parameter_list|,
name|CXSourceRange
name|range2
parameter_list|)
function_decl|;
comment|/**  * \brief Returns non-zero if \p range is null.  */
name|CINDEX_LINKAGE
name|int
name|clang_Range_isNull
parameter_list|(
name|CXSourceRange
name|range
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the file, line, column, and offset represented by  * the given source location.  *  * If the location refers into a macro expansion, retrieves the  * location of the macro expansion.  *  * \param location the location within a source file that will be decomposed  * into its parts.  *  * \param file [out] if non-NULL, will be set to the file to which the given  * source location points.  *  * \param line [out] if non-NULL, will be set to the line to which the given  * source location points.  *  * \param column [out] if non-NULL, will be set to the column to which the given  * source location points.  *  * \param offset [out] if non-NULL, will be set to the offset into the  * buffer to which the given source location points.  */
name|CINDEX_LINKAGE
name|void
name|clang_getExpansionLocation
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
comment|/**  * \brief Retrieve the file, line and column represented by the given source  * location, as specified in a # line directive.  *  * Example: given the following source code in a file somefile.c  *  * \code  * #123 "dummy.c" 1  *  * static int func(void)  * {  *     return 0;  * }  * \endcode  *  * the location information returned by this function would be  *  * File: dummy.c Line: 124 Column: 12  *  * whereas clang_getExpansionLocation would have returned  *  * File: somefile.c Line: 3 Column: 12  *  * \param location the location within a source file that will be decomposed  * into its parts.  *  * \param filename [out] if non-NULL, will be set to the filename of the  * source location. Note that filenames returned will be for "virtual" files,  * which don't necessarily exist on the machine running clang - e.g. when  * parsing preprocessed output obtained from a different environment. If  * a non-NULL value is passed in, remember to dispose of the returned value  * using \c clang_disposeString() once you've finished with it. For an invalid  * source location, an empty string is returned.  *  * \param line [out] if non-NULL, will be set to the line number of the  * source location. For an invalid source location, zero is returned.  *  * \param column [out] if non-NULL, will be set to the column number of the  * source location. For an invalid source location, zero is returned.  */
name|CINDEX_LINKAGE
name|void
name|clang_getPresumedLocation
parameter_list|(
name|CXSourceLocation
name|location
parameter_list|,
name|CXString
modifier|*
name|filename
parameter_list|,
name|unsigned
modifier|*
name|line
parameter_list|,
name|unsigned
modifier|*
name|column
parameter_list|)
function_decl|;
comment|/**  * \brief Legacy API to retrieve the file, line, column, and offset represented  * by the given source location.  *  * This interface has been replaced by the newer interface  * #clang_getExpansionLocation(). See that interface's documentation for  * details.  */
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
comment|/**  * \brief Retrieve the file, line, column, and offset represented by  * the given source location.  *  * If the location refers into a macro expansion, return where the macro was  * expanded or where the macro argument was written, if the location points at  * a macro argument.  *  * \param location the location within a source file that will be decomposed  * into its parts.  *  * \param file [out] if non-NULL, will be set to the file to which the given  * source location points.  *  * \param line [out] if non-NULL, will be set to the line to which the given  * source location points.  *  * \param column [out] if non-NULL, will be set to the column to which the given  * source location points.  *  * \param offset [out] if non-NULL, will be set to the offset into the  * buffer to which the given source location points.  */
name|CINDEX_LINKAGE
name|void
name|clang_getFileLocation
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
comment|/**  * \brief Identifies an array of ranges.  */
typedef|typedef
struct|struct
block|{
comment|/** \brief The number of ranges in the \c ranges array. */
name|unsigned
name|count
decl_stmt|;
comment|/**    * \brief An array of \c CXSourceRanges.    */
name|CXSourceRange
modifier|*
name|ranges
decl_stmt|;
block|}
name|CXSourceRangeList
typedef|;
comment|/**  * \brief Retrieve all ranges that were skipped by the preprocessor.  *  * The preprocessor will skip lines when they are surrounded by an  * if/ifdef/ifndef directive whose condition does not evaluate to true.  */
name|CINDEX_LINKAGE
name|CXSourceRangeList
modifier|*
name|clang_getSkippedRanges
parameter_list|(
name|CXTranslationUnit
name|tu
parameter_list|,
name|CXFile
name|file
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve all ranges from all files that were skipped by the  * preprocessor.  *  * The preprocessor will skip lines when they are surrounded by an  * if/ifdef/ifndef directive whose condition does not evaluate to true.  */
name|CINDEX_LINKAGE
name|CXSourceRangeList
modifier|*
name|clang_getAllSkippedRanges
parameter_list|(
name|CXTranslationUnit
name|tu
parameter_list|)
function_decl|;
comment|/**  * \brief Destroy the given \c CXSourceRangeList.  */
name|CINDEX_LINKAGE
name|void
name|clang_disposeSourceRangeList
parameter_list|(
name|CXSourceRangeList
modifier|*
name|ranges
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
comment|/**  * \brief A group of CXDiagnostics.  */
typedef|typedef
name|void
modifier|*
name|CXDiagnosticSet
typedef|;
comment|/**  * \brief Determine the number of diagnostics in a CXDiagnosticSet.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_getNumDiagnosticsInSet
parameter_list|(
name|CXDiagnosticSet
name|Diags
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve a diagnostic associated with the given CXDiagnosticSet.  *  * \param Diags the CXDiagnosticSet to query.  * \param Index the zero-based diagnostic number to retrieve.  *  * \returns the requested diagnostic. This diagnostic must be freed  * via a call to \c clang_disposeDiagnostic().  */
name|CINDEX_LINKAGE
name|CXDiagnostic
name|clang_getDiagnosticInSet
parameter_list|(
name|CXDiagnosticSet
name|Diags
parameter_list|,
name|unsigned
name|Index
parameter_list|)
function_decl|;
comment|/**  * \brief Describes the kind of error that occurred (if any) in a call to  * \c clang_loadDiagnostics.  */
enum|enum
name|CXLoadDiag_Error
block|{
comment|/**    * \brief Indicates that no error occurred.    */
name|CXLoadDiag_None
init|=
literal|0
block|,
comment|/**    * \brief Indicates that an unknown error occurred while attempting to    * deserialize diagnostics.    */
name|CXLoadDiag_Unknown
init|=
literal|1
block|,
comment|/**    * \brief Indicates that the file containing the serialized diagnostics    * could not be opened.    */
name|CXLoadDiag_CannotLoad
init|=
literal|2
block|,
comment|/**    * \brief Indicates that the serialized diagnostics file is invalid or    * corrupt.    */
name|CXLoadDiag_InvalidFile
init|=
literal|3
block|}
enum|;
comment|/**  * \brief Deserialize a set of diagnostics from a Clang diagnostics bitcode  * file.  *  * \param file The name of the file to deserialize.  * \param error A pointer to a enum value recording if there was a problem  *        deserializing the diagnostics.  * \param errorString A pointer to a CXString for recording the error string  *        if the file was not successfully loaded.  *  * \returns A loaded CXDiagnosticSet if successful, and NULL otherwise.  These  * diagnostics should be released using clang_disposeDiagnosticSet().  */
name|CINDEX_LINKAGE
name|CXDiagnosticSet
name|clang_loadDiagnostics
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|enum
name|CXLoadDiag_Error
modifier|*
name|error
parameter_list|,
name|CXString
modifier|*
name|errorString
parameter_list|)
function_decl|;
comment|/**  * \brief Release a CXDiagnosticSet and all of its contained diagnostics.  */
name|CINDEX_LINKAGE
name|void
name|clang_disposeDiagnosticSet
parameter_list|(
name|CXDiagnosticSet
name|Diags
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the child diagnostics of a CXDiagnostic.   *  * This CXDiagnosticSet does not need to be released by  * clang_disposeDiagnosticSet.  */
name|CINDEX_LINKAGE
name|CXDiagnosticSet
name|clang_getChildDiagnostics
parameter_list|(
name|CXDiagnostic
name|D
parameter_list|)
function_decl|;
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
comment|/**  * \brief Retrieve the complete set of diagnostics associated with a  *        translation unit.  *  * \param Unit the translation unit to query.  */
name|CINDEX_LINKAGE
name|CXDiagnosticSet
name|clang_getDiagnosticSetFromTU
parameter_list|(
name|CXTranslationUnit
name|Unit
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
comment|/**  * \brief Options to control the display of diagnostics.  *  * The values in this enum are meant to be combined to customize the  * behavior of \c clang_formatDiagnostic().  */
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
comment|/**  * \brief Retrieve the set of display options most similar to the  * default behavior of the clang compiler.  *  * \returns A set of display options suitable for use with \c  * clang_formatDiagnostic().  */
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
comment|/**  * \brief Retrieve the name of a particular diagnostic category.  This  *  is now deprecated.  Use clang_getDiagnosticCategoryText()  *  instead.  *  * \param Category A diagnostic category number, as returned by   * \c clang_getDiagnosticCategory().  *  * \returns The name of the given diagnostic category.  */
name|CINDEX_DEPRECATED
name|CINDEX_LINKAGE
name|CXString
name|clang_getDiagnosticCategoryName
parameter_list|(
name|unsigned
name|Category
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the diagnostic category text for a given diagnostic.  *  * \returns The text of the given diagnostic category.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_getDiagnosticCategoryText
parameter_list|(
name|CXDiagnostic
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
comment|/**  * \brief Return the CXTranslationUnit for a given source file and the provided  * command line arguments one would pass to the compiler.  *  * Note: The 'source_filename' argument is optional.  If the caller provides a  * NULL pointer, the name of the source file is expected to reside in the  * specified command line arguments.  *  * Note: When encountered in 'clang_command_line_args', the following options  * are ignored:  *  *   '-c'  *   '-emit-ast'  *   '-fsyntax-only'  *   '-o \<output file>'  (both '-o' and '\<output file>' are ignored)  *  * \param CIdx The index object with which the translation unit will be  * associated.  *  * \param source_filename The name of the source file to load, or NULL if the  * source file is included in \p clang_command_line_args.  *  * \param num_clang_command_line_args The number of command-line arguments in  * \p clang_command_line_args.  *  * \param clang_command_line_args The command-line arguments that would be  * passed to the \c clang executable if it were being invoked out-of-process.  * These command-line options will be parsed and will affect how the translation  * unit is parsed. Note that the following options are ignored: '-c',  * '-emit-ast', '-fsyntax-only' (which is the default), and '-o \<output file>'.  *  * \param num_unsaved_files the number of unsaved file entries in \p  * unsaved_files.  *  * \param unsaved_files the files that have not yet been saved to disk  * but may be required for code completion, including the contents of  * those files.  The contents and name of these files (as specified by  * CXUnsavedFile) are copied when necessary, so the client only needs to  * guarantee their validity until the call to this function returns.  */
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
comment|/**  * \brief Same as \c clang_createTranslationUnit2, but returns  * the \c CXTranslationUnit instead of an error code.  In case of an error this  * routine returns a \c NULL \c CXTranslationUnit, without further detailed  * error codes.  */
name|CINDEX_LINKAGE
name|CXTranslationUnit
name|clang_createTranslationUnit
parameter_list|(
name|CXIndex
name|CIdx
parameter_list|,
specifier|const
name|char
modifier|*
name|ast_filename
parameter_list|)
function_decl|;
comment|/**  * \brief Create a translation unit from an AST file (\c -emit-ast).  *  * \param[out] out_TU A non-NULL pointer to store the created  * \c CXTranslationUnit.  *  * \returns Zero on success, otherwise returns an error code.  */
name|CINDEX_LINKAGE
name|enum
name|CXErrorCode
name|clang_createTranslationUnit2
parameter_list|(
name|CXIndex
name|CIdx
parameter_list|,
specifier|const
name|char
modifier|*
name|ast_filename
parameter_list|,
name|CXTranslationUnit
modifier|*
name|out_TU
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
comment|/**    * \brief Used to indicate that the translation unit will be serialized with    * \c clang_saveTranslationUnit.    *    * This option is typically used when parsing a header with the intent of    * producing a precompiled header.    */
name|CXTranslationUnit_ForSerialization
init|=
literal|0x10
block|,
comment|/**    * \brief DEPRECATED: Enabled chained precompiled preambles in C++.    *    * Note: this is a *temporary* option that is available only while    * we are testing C++ precompiled preamble support. It is deprecated.    */
name|CXTranslationUnit_CXXChainedPCH
init|=
literal|0x20
block|,
comment|/**    * \brief Used to indicate that function/method bodies should be skipped while    * parsing.    *    * This option can be used to search for declarations/definitions while    * ignoring the usages.    */
name|CXTranslationUnit_SkipFunctionBodies
init|=
literal|0x40
block|,
comment|/**    * \brief Used to indicate that brief documentation comments should be    * included into the set of code completions returned from this translation    * unit.    */
name|CXTranslationUnit_IncludeBriefCommentsInCodeCompletion
init|=
literal|0x80
block|,
comment|/**    * \brief Used to indicate that the precompiled preamble should be created on    * the first parse. Otherwise it will be created on the first reparse. This    * trades runtime on the first parse (serializing the preamble takes time) for    * reduced runtime on the second parse (can now reuse the preamble).    */
name|CXTranslationUnit_CreatePreambleOnFirstParse
init|=
literal|0x100
block|,
comment|/**    * \brief Do not stop processing when fatal errors are encountered.    *    * When fatal errors are encountered while parsing a translation unit,    * semantic analysis is typically stopped early when compiling code. A common    * source for fatal errors are unresolvable include files. For the    * purposes of an IDE, this is undesirable behavior and as much information    * as possible should be reported. Use this flag to enable this behavior.    */
name|CXTranslationUnit_KeepGoing
init|=
literal|0x200
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
comment|/**  * \brief Same as \c clang_parseTranslationUnit2, but returns  * the \c CXTranslationUnit instead of an error code.  In case of an error this  * routine returns a \c NULL \c CXTranslationUnit, without further detailed  * error codes.  */
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
comment|/**  * \brief Parse the given source file and the translation unit corresponding  * to that file.  *  * This routine is the main entry point for the Clang C API, providing the  * ability to parse a source file into a translation unit that can then be  * queried by other functions in the API. This routine accepts a set of  * command-line arguments so that the compilation can be configured in the same  * way that the compiler is configured on the command line.  *  * \param CIdx The index object with which the translation unit will be   * associated.  *  * \param source_filename The name of the source file to load, or NULL if the  * source file is included in \c command_line_args.  *  * \param command_line_args The command-line arguments that would be  * passed to the \c clang executable if it were being invoked out-of-process.  * These command-line options will be parsed and will affect how the translation  * unit is parsed. Note that the following options are ignored: '-c',   * '-emit-ast', '-fsyntax-only' (which is the default), and '-o \<output file>'.  *  * \param num_command_line_args The number of command-line arguments in  * \c command_line_args.  *  * \param unsaved_files the files that have not yet been saved to disk  * but may be required for parsing, including the contents of  * those files.  The contents and name of these files (as specified by  * CXUnsavedFile) are copied when necessary, so the client only needs to  * guarantee their validity until the call to this function returns.  *  * \param num_unsaved_files the number of unsaved file entries in \p  * unsaved_files.  *  * \param options A bitmask of options that affects how the translation unit  * is managed but not its compilation. This should be a bitwise OR of the  * CXTranslationUnit_XXX flags.  *  * \param[out] out_TU A non-NULL pointer to store the created  * \c CXTranslationUnit, describing the parsed code and containing any  * diagnostics produced by the compiler.  *  * \returns Zero on success, otherwise returns an error code.  */
name|CINDEX_LINKAGE
name|enum
name|CXErrorCode
name|clang_parseTranslationUnit2
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
parameter_list|,
name|CXTranslationUnit
modifier|*
name|out_TU
parameter_list|)
function_decl|;
comment|/**  * \brief Same as clang_parseTranslationUnit2 but requires a full command line  * for \c command_line_args including argv[0]. This is useful if the standard  * library paths are relative to the binary.  */
name|CINDEX_LINKAGE
name|enum
name|CXErrorCode
name|clang_parseTranslationUnit2FullArgv
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
parameter_list|,
name|CXTranslationUnit
modifier|*
name|out_TU
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
comment|/**  * \brief Describes the kind of error that occurred (if any) in a call to  * \c clang_saveTranslationUnit().  */
enum|enum
name|CXSaveError
block|{
comment|/**    * \brief Indicates that no error occurred while saving a translation unit.    */
name|CXSaveError_None
init|=
literal|0
block|,
comment|/**    * \brief Indicates that an unknown error occurred while attempting to save    * the file.    *    * This error typically indicates that file I/O failed when attempting to     * write the file.    */
name|CXSaveError_Unknown
init|=
literal|1
block|,
comment|/**    * \brief Indicates that errors during translation prevented this attempt    * to save the translation unit.    *     * Errors that prevent the translation unit from being saved can be    * extracted using \c clang_getNumDiagnostics() and \c clang_getDiagnostic().    */
name|CXSaveError_TranslationErrors
init|=
literal|2
block|,
comment|/**    * \brief Indicates that the translation unit to be saved was somehow    * invalid (e.g., NULL).    */
name|CXSaveError_InvalidTU
init|=
literal|3
block|}
enum|;
comment|/**  * \brief Saves a translation unit into a serialized representation of  * that translation unit on disk.  *  * Any translation unit that was parsed without error can be saved  * into a file. The translation unit can then be deserialized into a  * new \c CXTranslationUnit with \c clang_createTranslationUnit() or,  * if it is an incomplete translation unit that corresponds to a  * header, used as a precompiled header when parsing other translation  * units.  *  * \param TU The translation unit to save.  *  * \param FileName The file to which the translation unit will be saved.  *  * \param options A bitmask of options that affects how the translation unit  * is saved. This should be a bitwise OR of the  * CXSaveTranslationUnit_XXX flags.  *  * \returns A value that will match one of the enumerators of the CXSaveError  * enumeration. Zero (CXSaveError_None) indicates that the translation unit was   * saved successfully, while a non-zero value indicates that a problem occurred.  */
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
comment|/**  * \brief Reparse the source files that produced this translation unit.  *  * This routine can be used to re-parse the source files that originally  * created the given translation unit, for example because those source files  * have changed (either on disk or as passed via \p unsaved_files). The  * source code will be reparsed with the same command-line options as it  * was originally parsed.   *  * Reparsing a translation unit invalidates all cursors and source locations  * that refer into that translation unit. This makes reparsing a translation  * unit semantically equivalent to destroying the translation unit and then  * creating a new translation unit with the same command-line arguments.  * However, it may be more efficient to reparse a translation   * unit using this routine.  *  * \param TU The translation unit whose contents will be re-parsed. The  * translation unit must originally have been built with   * \c clang_createTranslationUnitFromSourceFile().  *  * \param num_unsaved_files The number of unsaved file entries in \p  * unsaved_files.  *  * \param unsaved_files The files that have not yet been saved to disk  * but may be required for parsing, including the contents of  * those files.  The contents and name of these files (as specified by  * CXUnsavedFile) are copied when necessary, so the client only needs to  * guarantee their validity until the call to this function returns.  *   * \param options A bitset of options composed of the flags in CXReparse_Flags.  * The function \c clang_defaultReparseOptions() produces a default set of  * options recommended for most uses, based on the translation unit.  *  * \returns 0 if the sources could be reparsed.  A non-zero error code will be  * returned if reparsing was impossible, such that the translation unit is  * invalid. In such cases, the only valid call for \c TU is  * \c clang_disposeTranslationUnit(TU).  The error codes returned by this  * routine are described by the \c CXErrorCode enum.  */
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
comment|/**   * \brief Categorizes how memory is being used by a translation unit.   */
enum|enum
name|CXTUResourceUsageKind
block|{
name|CXTUResourceUsage_AST
init|=
literal|1
block|,
name|CXTUResourceUsage_Identifiers
init|=
literal|2
block|,
name|CXTUResourceUsage_Selectors
init|=
literal|3
block|,
name|CXTUResourceUsage_GlobalCompletionResults
init|=
literal|4
block|,
name|CXTUResourceUsage_SourceManagerContentCache
init|=
literal|5
block|,
name|CXTUResourceUsage_AST_SideTables
init|=
literal|6
block|,
name|CXTUResourceUsage_SourceManager_Membuffer_Malloc
init|=
literal|7
block|,
name|CXTUResourceUsage_SourceManager_Membuffer_MMap
init|=
literal|8
block|,
name|CXTUResourceUsage_ExternalASTSource_Membuffer_Malloc
init|=
literal|9
block|,
name|CXTUResourceUsage_ExternalASTSource_Membuffer_MMap
init|=
literal|10
block|,
name|CXTUResourceUsage_Preprocessor
init|=
literal|11
block|,
name|CXTUResourceUsage_PreprocessingRecord
init|=
literal|12
block|,
name|CXTUResourceUsage_SourceManager_DataStructures
init|=
literal|13
block|,
name|CXTUResourceUsage_Preprocessor_HeaderSearch
init|=
literal|14
block|,
name|CXTUResourceUsage_MEMORY_IN_BYTES_BEGIN
init|=
name|CXTUResourceUsage_AST
block|,
name|CXTUResourceUsage_MEMORY_IN_BYTES_END
init|=
name|CXTUResourceUsage_Preprocessor_HeaderSearch
block|,
name|CXTUResourceUsage_First
init|=
name|CXTUResourceUsage_AST
block|,
name|CXTUResourceUsage_Last
init|=
name|CXTUResourceUsage_Preprocessor_HeaderSearch
block|}
enum|;
comment|/**   * \brief Returns the human-readable null-terminated C string that represents   *  the name of the memory category.  This string should never be freed.   */
name|CINDEX_LINKAGE
specifier|const
name|char
modifier|*
name|clang_getTUResourceUsageName
parameter_list|(
name|enum
name|CXTUResourceUsageKind
name|kind
parameter_list|)
function_decl|;
typedef|typedef
struct|struct
name|CXTUResourceUsageEntry
block|{
comment|/* \brief The memory usage category. */
name|enum
name|CXTUResourceUsageKind
name|kind
decl_stmt|;
comment|/* \brief Amount of resources used.        The units will depend on the resource kind. */
name|unsigned
name|long
name|amount
decl_stmt|;
block|}
name|CXTUResourceUsageEntry
typedef|;
comment|/**   * \brief The memory usage of a CXTranslationUnit, broken into categories.   */
typedef|typedef
struct|struct
name|CXTUResourceUsage
block|{
comment|/* \brief Private data member, used for queries. */
name|void
modifier|*
name|data
decl_stmt|;
comment|/* \brief The number of entries in the 'entries' array. */
name|unsigned
name|numEntries
decl_stmt|;
comment|/* \brief An array of key-value pairs, representing the breakdown of memory             usage. */
name|CXTUResourceUsageEntry
modifier|*
name|entries
decl_stmt|;
block|}
name|CXTUResourceUsage
typedef|;
comment|/**   * \brief Return the memory usage of a translation unit.  This object   *  should be released with clang_disposeCXTUResourceUsage().   */
name|CINDEX_LINKAGE
name|CXTUResourceUsage
name|clang_getCXTUResourceUsage
parameter_list|(
name|CXTranslationUnit
name|TU
parameter_list|)
function_decl|;
name|CINDEX_LINKAGE
name|void
name|clang_disposeCXTUResourceUsage
parameter_list|(
name|CXTUResourceUsage
name|usage
parameter_list|)
function_decl|;
comment|/**  * \brief Get target information for this translation unit.  *  * The CXTargetInfo object cannot outlive the CXTranslationUnit object.  */
name|CINDEX_LINKAGE
name|CXTargetInfo
name|clang_getTranslationUnitTargetInfo
parameter_list|(
name|CXTranslationUnit
name|CTUnit
parameter_list|)
function_decl|;
comment|/**  * \brief Destroy the CXTargetInfo object.  */
name|CINDEX_LINKAGE
name|void
name|clang_TargetInfo_dispose
parameter_list|(
name|CXTargetInfo
name|Info
parameter_list|)
function_decl|;
comment|/**  * \brief Get the normalized target triple as a string.  *  * Returns the empty string in case of any error.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_TargetInfo_getTriple
parameter_list|(
name|CXTargetInfo
name|Info
parameter_list|)
function_decl|;
comment|/**  * \brief Get the pointer width of the target in bits.  *  * Returns -1 in case of error.  */
name|CINDEX_LINKAGE
name|int
name|clang_TargetInfo_getPointerWidth
parameter_list|(
name|CXTargetInfo
name|Info
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
comment|/** \brief An Objective-C \@interface. */
name|CXCursor_ObjCInterfaceDecl
init|=
literal|11
block|,
comment|/** \brief An Objective-C \@interface for a category. */
name|CXCursor_ObjCCategoryDecl
init|=
literal|12
block|,
comment|/** \brief An Objective-C \@protocol declaration. */
name|CXCursor_ObjCProtocolDecl
init|=
literal|13
block|,
comment|/** \brief An Objective-C \@property declaration. */
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
comment|/** \brief An Objective-C \@implementation. */
name|CXCursor_ObjCImplementationDecl
init|=
literal|18
block|,
comment|/** \brief An Objective-C \@implementation for a category. */
name|CXCursor_ObjCCategoryImplDecl
init|=
literal|19
block|,
comment|/** \brief A typedef. */
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
comment|/** \brief A C++ using declaration. */
name|CXCursor_UsingDeclaration
init|=
literal|35
block|,
comment|/** \brief A C++ alias declaration */
name|CXCursor_TypeAliasDecl
init|=
literal|36
block|,
comment|/** \brief An Objective-C \@synthesize definition. */
name|CXCursor_ObjCSynthesizeDecl
init|=
literal|37
block|,
comment|/** \brief An Objective-C \@dynamic definition. */
name|CXCursor_ObjCDynamicDecl
init|=
literal|38
block|,
comment|/** \brief An access specifier. */
name|CXCursor_CXXAccessSpecifier
init|=
literal|39
block|,
name|CXCursor_FirstDecl
init|=
name|CXCursor_UnexposedDecl
block|,
name|CXCursor_LastDecl
init|=
name|CXCursor_CXXAccessSpecifier
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
comment|/**    * \brief A reference to a variable that occurs in some non-expression     * context, e.g., a C++ lambda capture list.    */
name|CXCursor_VariableRef
init|=
literal|50
block|,
name|CXCursor_LastRef
init|=
name|CXCursor_VariableRef
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
comment|/**    * \brief An expression that refers to some value declaration, such    * as a function, variable, or enumerator.    */
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
comment|/** \brief An integer literal.    */
name|CXCursor_IntegerLiteral
init|=
literal|106
block|,
comment|/** \brief A floating point number literal.    */
name|CXCursor_FloatingLiteral
init|=
literal|107
block|,
comment|/** \brief An imaginary number literal.    */
name|CXCursor_ImaginaryLiteral
init|=
literal|108
block|,
comment|/** \brief A string literal.    */
name|CXCursor_StringLiteral
init|=
literal|109
block|,
comment|/** \brief A character literal.    */
name|CXCursor_CharacterLiteral
init|=
literal|110
block|,
comment|/** \brief A parenthesized expression, e.g. "(1)".    *    * This AST node is only formed if full location information is requested.    */
name|CXCursor_ParenExpr
init|=
literal|111
block|,
comment|/** \brief This represents the unary-expression's (except sizeof and    * alignof).    */
name|CXCursor_UnaryOperator
init|=
literal|112
block|,
comment|/** \brief [C99 6.5.2.1] Array Subscripting.    */
name|CXCursor_ArraySubscriptExpr
init|=
literal|113
block|,
comment|/** \brief A builtin binary operation expression such as "x + y" or    * "x<= y".    */
name|CXCursor_BinaryOperator
init|=
literal|114
block|,
comment|/** \brief Compound assignment such as "+=".    */
name|CXCursor_CompoundAssignOperator
init|=
literal|115
block|,
comment|/** \brief The ?: ternary operator.    */
name|CXCursor_ConditionalOperator
init|=
literal|116
block|,
comment|/** \brief An explicit cast in C (C99 6.5.4) or a C-style cast in C++    * (C++ [expr.cast]), which uses the syntax (Type)expr.    *    * For example: (int)f.    */
name|CXCursor_CStyleCastExpr
init|=
literal|117
block|,
comment|/** \brief [C99 6.5.2.5]    */
name|CXCursor_CompoundLiteralExpr
init|=
literal|118
block|,
comment|/** \brief Describes an C or C++ initializer list.    */
name|CXCursor_InitListExpr
init|=
literal|119
block|,
comment|/** \brief The GNU address of label extension, representing&&label.    */
name|CXCursor_AddrLabelExpr
init|=
literal|120
block|,
comment|/** \brief This is the GNU Statement Expression extension: ({int X=4; X;})    */
name|CXCursor_StmtExpr
init|=
literal|121
block|,
comment|/** \brief Represents a C11 generic selection.    */
name|CXCursor_GenericSelectionExpr
init|=
literal|122
block|,
comment|/** \brief Implements the GNU __null extension, which is a name for a null    * pointer constant that has integral type (e.g., int or long) and is the same    * size and alignment as a pointer.    *    * The __null extension is typically only used by system headers, which define    * NULL as __null in C++ rather than using 0 (which is an integer that may not    * match the size of a pointer).    */
name|CXCursor_GNUNullExpr
init|=
literal|123
block|,
comment|/** \brief C++'s static_cast<> expression.    */
name|CXCursor_CXXStaticCastExpr
init|=
literal|124
block|,
comment|/** \brief C++'s dynamic_cast<> expression.    */
name|CXCursor_CXXDynamicCastExpr
init|=
literal|125
block|,
comment|/** \brief C++'s reinterpret_cast<> expression.    */
name|CXCursor_CXXReinterpretCastExpr
init|=
literal|126
block|,
comment|/** \brief C++'s const_cast<> expression.    */
name|CXCursor_CXXConstCastExpr
init|=
literal|127
block|,
comment|/** \brief Represents an explicit C++ type conversion that uses "functional"    * notion (C++ [expr.type.conv]).    *    * Example:    * \code    *   x = int(0.5);    * \endcode    */
name|CXCursor_CXXFunctionalCastExpr
init|=
literal|128
block|,
comment|/** \brief A C++ typeid expression (C++ [expr.typeid]).    */
name|CXCursor_CXXTypeidExpr
init|=
literal|129
block|,
comment|/** \brief [C++ 2.13.5] C++ Boolean Literal.    */
name|CXCursor_CXXBoolLiteralExpr
init|=
literal|130
block|,
comment|/** \brief [C++0x 2.14.7] C++ Pointer Literal.    */
name|CXCursor_CXXNullPtrLiteralExpr
init|=
literal|131
block|,
comment|/** \brief Represents the "this" expression in C++    */
name|CXCursor_CXXThisExpr
init|=
literal|132
block|,
comment|/** \brief [C++ 15] C++ Throw Expression.    *    * This handles 'throw' and 'throw' assignment-expression. When    * assignment-expression isn't present, Op will be null.    */
name|CXCursor_CXXThrowExpr
init|=
literal|133
block|,
comment|/** \brief A new expression for memory allocation and constructor calls, e.g:    * "new CXXNewExpr(foo)".    */
name|CXCursor_CXXNewExpr
init|=
literal|134
block|,
comment|/** \brief A delete expression for memory deallocation and destructor calls,    * e.g. "delete[] pArray".    */
name|CXCursor_CXXDeleteExpr
init|=
literal|135
block|,
comment|/** \brief A unary expression. (noexcept, sizeof, or other traits)    */
name|CXCursor_UnaryExpr
init|=
literal|136
block|,
comment|/** \brief An Objective-C string literal i.e. @"foo".    */
name|CXCursor_ObjCStringLiteral
init|=
literal|137
block|,
comment|/** \brief An Objective-C \@encode expression.    */
name|CXCursor_ObjCEncodeExpr
init|=
literal|138
block|,
comment|/** \brief An Objective-C \@selector expression.    */
name|CXCursor_ObjCSelectorExpr
init|=
literal|139
block|,
comment|/** \brief An Objective-C \@protocol expression.    */
name|CXCursor_ObjCProtocolExpr
init|=
literal|140
block|,
comment|/** \brief An Objective-C "bridged" cast expression, which casts between    * Objective-C pointers and C pointers, transferring ownership in the process.    *    * \code    *   NSString *str = (__bridge_transfer NSString *)CFCreateString();    * \endcode    */
name|CXCursor_ObjCBridgedCastExpr
init|=
literal|141
block|,
comment|/** \brief Represents a C++0x pack expansion that produces a sequence of    * expressions.    *    * A pack expansion expression contains a pattern (which itself is an    * expression) followed by an ellipsis. For example:    *    * \code    * template<typename F, typename ...Types>    * void forward(F f, Types&&...args) {    *  f(static_cast<Types&&>(args)...);    * }    * \endcode    */
name|CXCursor_PackExpansionExpr
init|=
literal|142
block|,
comment|/** \brief Represents an expression that computes the length of a parameter    * pack.    *    * \code    * template<typename ...Types>    * struct count {    *   static const unsigned value = sizeof...(Types);    * };    * \endcode    */
name|CXCursor_SizeOfPackExpr
init|=
literal|143
block|,
comment|/* \brief Represents a C++ lambda expression that produces a local function    * object.    *    * \code    * void abssort(float *x, unsigned N) {    *   std::sort(x, x + N,    *             [](float a, float b) {    *               return std::abs(a)< std::abs(b);    *             });    * }    * \endcode    */
name|CXCursor_LambdaExpr
init|=
literal|144
block|,
comment|/** \brief Objective-c Boolean Literal.    */
name|CXCursor_ObjCBoolLiteralExpr
init|=
literal|145
block|,
comment|/** \brief Represents the "self" expression in an Objective-C method.    */
name|CXCursor_ObjCSelfExpr
init|=
literal|146
block|,
comment|/** \brief OpenMP 4.0 [2.4, Array Section].    */
name|CXCursor_OMPArraySectionExpr
init|=
literal|147
block|,
comment|/** \brief Represents an @available(...) check.    */
name|CXCursor_ObjCAvailabilityCheckExpr
init|=
literal|148
block|,
name|CXCursor_LastExpr
init|=
name|CXCursor_ObjCAvailabilityCheckExpr
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
comment|/** \brief A group of statements like { stmt stmt }.    *    * This cursor kind is used to describe compound statements, e.g. function    * bodies.    */
name|CXCursor_CompoundStmt
init|=
literal|202
block|,
comment|/** \brief A case statement.    */
name|CXCursor_CaseStmt
init|=
literal|203
block|,
comment|/** \brief A default statement.    */
name|CXCursor_DefaultStmt
init|=
literal|204
block|,
comment|/** \brief An if statement    */
name|CXCursor_IfStmt
init|=
literal|205
block|,
comment|/** \brief A switch statement.    */
name|CXCursor_SwitchStmt
init|=
literal|206
block|,
comment|/** \brief A while statement.    */
name|CXCursor_WhileStmt
init|=
literal|207
block|,
comment|/** \brief A do statement.    */
name|CXCursor_DoStmt
init|=
literal|208
block|,
comment|/** \brief A for statement.    */
name|CXCursor_ForStmt
init|=
literal|209
block|,
comment|/** \brief A goto statement.    */
name|CXCursor_GotoStmt
init|=
literal|210
block|,
comment|/** \brief An indirect goto statement.    */
name|CXCursor_IndirectGotoStmt
init|=
literal|211
block|,
comment|/** \brief A continue statement.    */
name|CXCursor_ContinueStmt
init|=
literal|212
block|,
comment|/** \brief A break statement.    */
name|CXCursor_BreakStmt
init|=
literal|213
block|,
comment|/** \brief A return statement.    */
name|CXCursor_ReturnStmt
init|=
literal|214
block|,
comment|/** \brief A GCC inline assembly statement extension.    */
name|CXCursor_GCCAsmStmt
init|=
literal|215
block|,
name|CXCursor_AsmStmt
init|=
name|CXCursor_GCCAsmStmt
block|,
comment|/** \brief Objective-C's overall \@try-\@catch-\@finally statement.    */
name|CXCursor_ObjCAtTryStmt
init|=
literal|216
block|,
comment|/** \brief Objective-C's \@catch statement.    */
name|CXCursor_ObjCAtCatchStmt
init|=
literal|217
block|,
comment|/** \brief Objective-C's \@finally statement.    */
name|CXCursor_ObjCAtFinallyStmt
init|=
literal|218
block|,
comment|/** \brief Objective-C's \@throw statement.    */
name|CXCursor_ObjCAtThrowStmt
init|=
literal|219
block|,
comment|/** \brief Objective-C's \@synchronized statement.    */
name|CXCursor_ObjCAtSynchronizedStmt
init|=
literal|220
block|,
comment|/** \brief Objective-C's autorelease pool statement.    */
name|CXCursor_ObjCAutoreleasePoolStmt
init|=
literal|221
block|,
comment|/** \brief Objective-C's collection statement.    */
name|CXCursor_ObjCForCollectionStmt
init|=
literal|222
block|,
comment|/** \brief C++'s catch statement.    */
name|CXCursor_CXXCatchStmt
init|=
literal|223
block|,
comment|/** \brief C++'s try statement.    */
name|CXCursor_CXXTryStmt
init|=
literal|224
block|,
comment|/** \brief C++'s for (* : *) statement.    */
name|CXCursor_CXXForRangeStmt
init|=
literal|225
block|,
comment|/** \brief Windows Structured Exception Handling's try statement.    */
name|CXCursor_SEHTryStmt
init|=
literal|226
block|,
comment|/** \brief Windows Structured Exception Handling's except statement.    */
name|CXCursor_SEHExceptStmt
init|=
literal|227
block|,
comment|/** \brief Windows Structured Exception Handling's finally statement.    */
name|CXCursor_SEHFinallyStmt
init|=
literal|228
block|,
comment|/** \brief A MS inline assembly statement extension.    */
name|CXCursor_MSAsmStmt
init|=
literal|229
block|,
comment|/** \brief The null statement ";": C99 6.8.3p3.    *    * This cursor kind is used to describe the null statement.    */
name|CXCursor_NullStmt
init|=
literal|230
block|,
comment|/** \brief Adaptor class for mixing declarations with statements and    * expressions.    */
name|CXCursor_DeclStmt
init|=
literal|231
block|,
comment|/** \brief OpenMP parallel directive.    */
name|CXCursor_OMPParallelDirective
init|=
literal|232
block|,
comment|/** \brief OpenMP SIMD directive.    */
name|CXCursor_OMPSimdDirective
init|=
literal|233
block|,
comment|/** \brief OpenMP for directive.    */
name|CXCursor_OMPForDirective
init|=
literal|234
block|,
comment|/** \brief OpenMP sections directive.    */
name|CXCursor_OMPSectionsDirective
init|=
literal|235
block|,
comment|/** \brief OpenMP section directive.    */
name|CXCursor_OMPSectionDirective
init|=
literal|236
block|,
comment|/** \brief OpenMP single directive.    */
name|CXCursor_OMPSingleDirective
init|=
literal|237
block|,
comment|/** \brief OpenMP parallel for directive.    */
name|CXCursor_OMPParallelForDirective
init|=
literal|238
block|,
comment|/** \brief OpenMP parallel sections directive.    */
name|CXCursor_OMPParallelSectionsDirective
init|=
literal|239
block|,
comment|/** \brief OpenMP task directive.    */
name|CXCursor_OMPTaskDirective
init|=
literal|240
block|,
comment|/** \brief OpenMP master directive.    */
name|CXCursor_OMPMasterDirective
init|=
literal|241
block|,
comment|/** \brief OpenMP critical directive.    */
name|CXCursor_OMPCriticalDirective
init|=
literal|242
block|,
comment|/** \brief OpenMP taskyield directive.    */
name|CXCursor_OMPTaskyieldDirective
init|=
literal|243
block|,
comment|/** \brief OpenMP barrier directive.    */
name|CXCursor_OMPBarrierDirective
init|=
literal|244
block|,
comment|/** \brief OpenMP taskwait directive.    */
name|CXCursor_OMPTaskwaitDirective
init|=
literal|245
block|,
comment|/** \brief OpenMP flush directive.    */
name|CXCursor_OMPFlushDirective
init|=
literal|246
block|,
comment|/** \brief Windows Structured Exception Handling's leave statement.    */
name|CXCursor_SEHLeaveStmt
init|=
literal|247
block|,
comment|/** \brief OpenMP ordered directive.    */
name|CXCursor_OMPOrderedDirective
init|=
literal|248
block|,
comment|/** \brief OpenMP atomic directive.    */
name|CXCursor_OMPAtomicDirective
init|=
literal|249
block|,
comment|/** \brief OpenMP for SIMD directive.    */
name|CXCursor_OMPForSimdDirective
init|=
literal|250
block|,
comment|/** \brief OpenMP parallel for SIMD directive.    */
name|CXCursor_OMPParallelForSimdDirective
init|=
literal|251
block|,
comment|/** \brief OpenMP target directive.    */
name|CXCursor_OMPTargetDirective
init|=
literal|252
block|,
comment|/** \brief OpenMP teams directive.    */
name|CXCursor_OMPTeamsDirective
init|=
literal|253
block|,
comment|/** \brief OpenMP taskgroup directive.    */
name|CXCursor_OMPTaskgroupDirective
init|=
literal|254
block|,
comment|/** \brief OpenMP cancellation point directive.    */
name|CXCursor_OMPCancellationPointDirective
init|=
literal|255
block|,
comment|/** \brief OpenMP cancel directive.    */
name|CXCursor_OMPCancelDirective
init|=
literal|256
block|,
comment|/** \brief OpenMP target data directive.    */
name|CXCursor_OMPTargetDataDirective
init|=
literal|257
block|,
comment|/** \brief OpenMP taskloop directive.    */
name|CXCursor_OMPTaskLoopDirective
init|=
literal|258
block|,
comment|/** \brief OpenMP taskloop simd directive.    */
name|CXCursor_OMPTaskLoopSimdDirective
init|=
literal|259
block|,
comment|/** \brief OpenMP distribute directive.    */
name|CXCursor_OMPDistributeDirective
init|=
literal|260
block|,
comment|/** \brief OpenMP target enter data directive.    */
name|CXCursor_OMPTargetEnterDataDirective
init|=
literal|261
block|,
comment|/** \brief OpenMP target exit data directive.    */
name|CXCursor_OMPTargetExitDataDirective
init|=
literal|262
block|,
comment|/** \brief OpenMP target parallel directive.    */
name|CXCursor_OMPTargetParallelDirective
init|=
literal|263
block|,
comment|/** \brief OpenMP target parallel for directive.    */
name|CXCursor_OMPTargetParallelForDirective
init|=
literal|264
block|,
comment|/** \brief OpenMP target update directive.    */
name|CXCursor_OMPTargetUpdateDirective
init|=
literal|265
block|,
comment|/** \brief OpenMP distribute parallel for directive.    */
name|CXCursor_OMPDistributeParallelForDirective
init|=
literal|266
block|,
comment|/** \brief OpenMP distribute parallel for simd directive.    */
name|CXCursor_OMPDistributeParallelForSimdDirective
init|=
literal|267
block|,
comment|/** \brief OpenMP distribute simd directive.    */
name|CXCursor_OMPDistributeSimdDirective
init|=
literal|268
block|,
comment|/** \brief OpenMP target parallel for simd directive.    */
name|CXCursor_OMPTargetParallelForSimdDirective
init|=
literal|269
block|,
comment|/** \brief OpenMP target simd directive.    */
name|CXCursor_OMPTargetSimdDirective
init|=
literal|270
block|,
comment|/** \brief OpenMP teams distribute directive.    */
name|CXCursor_OMPTeamsDistributeDirective
init|=
literal|271
block|,
comment|/** \brief OpenMP teams distribute simd directive.    */
name|CXCursor_OMPTeamsDistributeSimdDirective
init|=
literal|272
block|,
comment|/** \brief OpenMP teams distribute parallel for simd directive.    */
name|CXCursor_OMPTeamsDistributeParallelForSimdDirective
init|=
literal|273
block|,
comment|/** \brief OpenMP teams distribute parallel for directive.    */
name|CXCursor_OMPTeamsDistributeParallelForDirective
init|=
literal|274
block|,
comment|/** \brief OpenMP target teams directive.    */
name|CXCursor_OMPTargetTeamsDirective
init|=
literal|275
block|,
comment|/** \brief OpenMP target teams distribute directive.    */
name|CXCursor_OMPTargetTeamsDistributeDirective
init|=
literal|276
block|,
comment|/** \brief OpenMP target teams distribute parallel for directive.    */
name|CXCursor_OMPTargetTeamsDistributeParallelForDirective
init|=
literal|277
block|,
comment|/** \brief OpenMP target teams distribute parallel for simd directive.    */
name|CXCursor_OMPTargetTeamsDistributeParallelForSimdDirective
init|=
literal|278
block|,
comment|/** \brief OpenMP target teams distribute simd directive.    */
name|CXCursor_OMPTargetTeamsDistributeSimdDirective
init|=
literal|279
block|,
name|CXCursor_LastStmt
init|=
name|CXCursor_OMPTargetTeamsDistributeSimdDirective
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
name|CXCursor_CXXFinalAttr
init|=
literal|404
block|,
name|CXCursor_CXXOverrideAttr
init|=
literal|405
block|,
name|CXCursor_AnnotateAttr
init|=
literal|406
block|,
name|CXCursor_AsmLabelAttr
init|=
literal|407
block|,
name|CXCursor_PackedAttr
init|=
literal|408
block|,
name|CXCursor_PureAttr
init|=
literal|409
block|,
name|CXCursor_ConstAttr
init|=
literal|410
block|,
name|CXCursor_NoDuplicateAttr
init|=
literal|411
block|,
name|CXCursor_CUDAConstantAttr
init|=
literal|412
block|,
name|CXCursor_CUDADeviceAttr
init|=
literal|413
block|,
name|CXCursor_CUDAGlobalAttr
init|=
literal|414
block|,
name|CXCursor_CUDAHostAttr
init|=
literal|415
block|,
name|CXCursor_CUDASharedAttr
init|=
literal|416
block|,
name|CXCursor_VisibilityAttr
init|=
literal|417
block|,
name|CXCursor_DLLExport
init|=
literal|418
block|,
name|CXCursor_DLLImport
init|=
literal|419
block|,
name|CXCursor_LastAttr
init|=
name|CXCursor_DLLImport
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
name|CXCursor_MacroExpansion
init|=
literal|502
block|,
name|CXCursor_MacroInstantiation
init|=
name|CXCursor_MacroExpansion
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
block|,
comment|/* Extra Declarations */
comment|/**    * \brief A module import declaration.    */
name|CXCursor_ModuleImportDecl
init|=
literal|600
block|,
name|CXCursor_TypeAliasTemplateDecl
init|=
literal|601
block|,
comment|/**    * \brief A static_assert or _Static_assert node    */
name|CXCursor_StaticAssert
init|=
literal|602
block|,
comment|/**    * \brief a friend declaration.    */
name|CXCursor_FriendDecl
init|=
literal|603
block|,
name|CXCursor_FirstExtraDecl
init|=
name|CXCursor_ModuleImportDecl
block|,
name|CXCursor_LastExtraDecl
init|=
name|CXCursor_FriendDecl
block|,
comment|/**    * \brief A code completion overload candidate.    */
name|CXCursor_OverloadCandidate
init|=
literal|700
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
name|int
name|xdata
decl_stmt|;
specifier|const
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
comment|/**  * \brief Returns non-zero if \p cursor is null.  */
name|CINDEX_LINKAGE
name|int
name|clang_Cursor_isNull
parameter_list|(
name|CXCursor
name|cursor
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
comment|/**  * \brief Determine whether the given cursor kind represents an attribute.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_isAttribute
parameter_list|(
name|enum
name|CXCursorKind
parameter_list|)
function_decl|;
comment|/**  * \brief Determine whether the given cursor has any attributes.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_Cursor_hasAttrs
parameter_list|(
name|CXCursor
name|C
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
enum|enum
name|CXVisibilityKind
block|{
comment|/** \brief This value indicates that no visibility information is available    * for a provided CXCursor. */
name|CXVisibility_Invalid
block|,
comment|/** \brief Symbol not seen by the linker. */
name|CXVisibility_Hidden
block|,
comment|/** \brief Symbol seen by the linker but resolves to a symbol inside this object. */
name|CXVisibility_Protected
block|,
comment|/** \brief Symbol seen by the linker and acts like a normal symbol. */
name|CXVisibility_Default
block|}
enum|;
comment|/**  * \brief Describe the visibility of the entity referred to by a cursor.  *  * This returns the default visibility if not explicitly specified by  * a visibility attribute. The default visibility may be changed by  * commandline arguments.  *  * \param cursor The cursor to query.  *  * \returns The visibility of the cursor.  */
name|CINDEX_LINKAGE
name|enum
name|CXVisibilityKind
name|clang_getCursorVisibility
parameter_list|(
name|CXCursor
name|cursor
parameter_list|)
function_decl|;
comment|/**  * \brief Determine the availability of the entity that this cursor refers to,  * taking the current target platform into account.  *  * \param cursor The cursor to query.  *  * \returns The availability of the cursor.  */
name|CINDEX_LINKAGE
name|enum
name|CXAvailabilityKind
name|clang_getCursorAvailability
parameter_list|(
name|CXCursor
name|cursor
parameter_list|)
function_decl|;
comment|/**  * Describes the availability of a given entity on a particular platform, e.g.,  * a particular class might only be available on Mac OS 10.7 or newer.  */
typedef|typedef
struct|struct
name|CXPlatformAvailability
block|{
comment|/**    * \brief A string that describes the platform for which this structure    * provides availability information.    *    * Possible values are "ios" or "macos".    */
name|CXString
name|Platform
decl_stmt|;
comment|/**    * \brief The version number in which this entity was introduced.    */
name|CXVersion
name|Introduced
decl_stmt|;
comment|/**    * \brief The version number in which this entity was deprecated (but is    * still available).    */
name|CXVersion
name|Deprecated
decl_stmt|;
comment|/**    * \brief The version number in which this entity was obsoleted, and therefore    * is no longer available.    */
name|CXVersion
name|Obsoleted
decl_stmt|;
comment|/**    * \brief Whether the entity is unconditionally unavailable on this platform.    */
name|int
name|Unavailable
decl_stmt|;
comment|/**    * \brief An optional message to provide to a user of this API, e.g., to    * suggest replacement APIs.    */
name|CXString
name|Message
decl_stmt|;
block|}
name|CXPlatformAvailability
typedef|;
comment|/**  * \brief Determine the availability of the entity that this cursor refers to  * on any platforms for which availability information is known.  *  * \param cursor The cursor to query.  *  * \param always_deprecated If non-NULL, will be set to indicate whether the   * entity is deprecated on all platforms.  *  * \param deprecated_message If non-NULL, will be set to the message text   * provided along with the unconditional deprecation of this entity. The client  * is responsible for deallocating this string.  *  * \param always_unavailable If non-NULL, will be set to indicate whether the  * entity is unavailable on all platforms.  *  * \param unavailable_message If non-NULL, will be set to the message text  * provided along with the unconditional unavailability of this entity. The   * client is responsible for deallocating this string.  *  * \param availability If non-NULL, an array of CXPlatformAvailability instances  * that will be populated with platform availability information, up to either  * the number of platforms for which availability information is available (as  * returned by this function) or \c availability_size, whichever is smaller.  *  * \param availability_size The number of elements available in the   * \c availability array.  *  * \returns The number of platforms (N) for which availability information is  * available (which is unrelated to \c availability_size).  *  * Note that the client is responsible for calling   * \c clang_disposeCXPlatformAvailability to free each of the   * platform-availability structures returned. There are   * \c min(N, availability_size) such structures.  */
name|CINDEX_LINKAGE
name|int
name|clang_getCursorPlatformAvailability
parameter_list|(
name|CXCursor
name|cursor
parameter_list|,
name|int
modifier|*
name|always_deprecated
parameter_list|,
name|CXString
modifier|*
name|deprecated_message
parameter_list|,
name|int
modifier|*
name|always_unavailable
parameter_list|,
name|CXString
modifier|*
name|unavailable_message
parameter_list|,
name|CXPlatformAvailability
modifier|*
name|availability
parameter_list|,
name|int
name|availability_size
parameter_list|)
function_decl|;
comment|/**  * \brief Free the memory associated with a \c CXPlatformAvailability structure.  */
name|CINDEX_LINKAGE
name|void
name|clang_disposeCXPlatformAvailability
parameter_list|(
name|CXPlatformAvailability
modifier|*
name|availability
parameter_list|)
function_decl|;
comment|/**  * \brief Describe the "language" of the entity referred to by a cursor.  */
enum|enum
name|CXLanguageKind
block|{
name|CXLanguage_Invalid
init|=
literal|0
block|,
name|CXLanguage_C
block|,
name|CXLanguage_ObjC
block|,
name|CXLanguage_CPlusPlus
block|}
enum|;
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
comment|/**  * \brief Returns the translation unit that a cursor originated from.  */
name|CINDEX_LINKAGE
name|CXTranslationUnit
name|clang_Cursor_getTranslationUnit
parameter_list|(
name|CXCursor
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
parameter_list|(
name|void
parameter_list|)
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
comment|/**  * \brief Determine the semantic parent of the given cursor.  *  * The semantic parent of a cursor is the cursor that semantically contains  * the given \p cursor. For many declarations, the lexical and semantic parents  * are equivalent (the lexical parent is returned by   * \c clang_getCursorLexicalParent()). They diverge when declarations or  * definitions are provided out-of-line. For example:  *  * \code  * class C {  *  void f();  * };  *  * void C::f() { }  * \endcode  *  * In the out-of-line definition of \c C::f, the semantic parent is  * the class \c C, of which this function is a member. The lexical parent is  * the place where the declaration actually occurs in the source code; in this  * case, the definition occurs in the translation unit. In general, the  * lexical parent for a given entity can change without affecting the semantics  * of the program, and the lexical parent of different declarations of the  * same entity may be different. Changing the semantic parent of a declaration,  * on the other hand, can have a major impact on semantics, and redeclarations  * of a particular entity should all have the same semantic context.  *  * In the example above, both declarations of \c C::f have \c C as their  * semantic context, while the lexical context of the first \c C::f is \c C  * and the lexical context of the second \c C::f is the translation unit.  *  * For global declarations, the semantic parent is the translation unit.  */
name|CINDEX_LINKAGE
name|CXCursor
name|clang_getCursorSemanticParent
parameter_list|(
name|CXCursor
name|cursor
parameter_list|)
function_decl|;
comment|/**  * \brief Determine the lexical parent of the given cursor.  *  * The lexical parent of a cursor is the cursor in which the given \p cursor  * was actually written. For many declarations, the lexical and semantic parents  * are equivalent (the semantic parent is returned by   * \c clang_getCursorSemanticParent()). They diverge when declarations or  * definitions are provided out-of-line. For example:  *  * \code  * class C {  *  void f();  * };  *  * void C::f() { }  * \endcode  *  * In the out-of-line definition of \c C::f, the semantic parent is  * the class \c C, of which this function is a member. The lexical parent is  * the place where the declaration actually occurs in the source code; in this  * case, the definition occurs in the translation unit. In general, the  * lexical parent for a given entity can change without affecting the semantics  * of the program, and the lexical parent of different declarations of the  * same entity may be different. Changing the semantic parent of a declaration,  * on the other hand, can have a major impact on semantics, and redeclarations  * of a particular entity should all have the same semantic context.  *  * In the example above, both declarations of \c C::f have \c C as their  * semantic context, while the lexical context of the first \c C::f is \c C  * and the lexical context of the second \c C::f is the translation unit.  *  * For declarations written in the global scope, the lexical parent is  * the translation unit.  */
name|CINDEX_LINKAGE
name|CXCursor
name|clang_getCursorLexicalParent
parameter_list|(
name|CXCursor
name|cursor
parameter_list|)
function_decl|;
comment|/**  * \brief Determine the set of methods that are overridden by the given  * method.  *  * In both Objective-C and C++, a method (aka virtual member function,  * in C++) can override a virtual method in a base class. For  * Objective-C, a method is said to override any method in the class's  * base class, its protocols, or its categories' protocols, that has the same  * selector and is of the same kind (class or instance).  * If no such method exists, the search continues to the class's superclass,  * its protocols, and its categories, and so on. A method from an Objective-C  * implementation is considered to override the same methods as its  * corresponding method in the interface.  *  * For C++, a virtual member function overrides any virtual member  * function with the same signature that occurs in its base  * classes. With multiple inheritance, a virtual member function can  * override several virtual member functions coming from different  * base classes.  *  * In all cases, this function determines the immediate overridden  * method, rather than all of the overridden methods. For example, if  * a method is originally declared in a class A, then overridden in B  * (which in inherits from A) and also in C (which inherited from B),  * then the only overridden method returned from this function when  * invoked on C's method will be B's method. The client may then  * invoke this function again, given the previously-found overridden  * methods, to map out the complete method-override set.  *  * \param cursor A cursor representing an Objective-C or C++  * method. This routine will compute the set of methods that this  * method overrides.  *   * \param overridden A pointer whose pointee will be replaced with a  * pointer to an array of cursors, representing the set of overridden  * methods. If there are no overridden methods, the pointee will be  * set to NULL. The pointee must be freed via a call to   * \c clang_disposeOverriddenCursors().  *  * \param num_overridden A pointer to the number of overridden  * functions, will be set to the number of overridden functions in the  * array pointed to by \p overridden.  */
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
comment|/**  * \brief Retrieve the physical extent of the source construct referenced by  * the given cursor.  *  * The extent of a cursor starts with the file/line/column pointing at the  * first character within the source construct that the cursor refers to and  * ends with the last character within that source construct. For a  * declaration, the extent covers the declaration itself. For a reference,  * the extent covers the location of the reference (e.g., where the referenced  * entity was actually used).  */
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
comment|/**    * \brief Represents an invalid type (e.g., where no type is available).    */
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
name|CXType_Float128
init|=
literal|30
block|,
name|CXType_Half
init|=
literal|31
block|,
name|CXType_FirstBuiltin
init|=
name|CXType_Void
block|,
name|CXType_LastBuiltin
init|=
name|CXType_Half
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
block|,
name|CXType_ConstantArray
init|=
literal|112
block|,
name|CXType_Vector
init|=
literal|113
block|,
name|CXType_IncompleteArray
init|=
literal|114
block|,
name|CXType_VariableArray
init|=
literal|115
block|,
name|CXType_DependentSizedArray
init|=
literal|116
block|,
name|CXType_MemberPointer
init|=
literal|117
block|,
name|CXType_Auto
init|=
literal|118
block|,
comment|/**    * \brief Represents a type that was referred to using an elaborated type keyword.    *    * E.g., struct S, or via a qualified name, e.g., N::M::type, or both.    */
name|CXType_Elaborated
init|=
literal|119
block|}
enum|;
comment|/**  * \brief Describes the calling convention of a function type  */
enum|enum
name|CXCallingConv
block|{
name|CXCallingConv_Default
init|=
literal|0
block|,
name|CXCallingConv_C
init|=
literal|1
block|,
name|CXCallingConv_X86StdCall
init|=
literal|2
block|,
name|CXCallingConv_X86FastCall
init|=
literal|3
block|,
name|CXCallingConv_X86ThisCall
init|=
literal|4
block|,
name|CXCallingConv_X86Pascal
init|=
literal|5
block|,
name|CXCallingConv_AAPCS
init|=
literal|6
block|,
name|CXCallingConv_AAPCS_VFP
init|=
literal|7
block|,
name|CXCallingConv_X86RegCall
init|=
literal|8
block|,
name|CXCallingConv_IntelOclBicc
init|=
literal|9
block|,
name|CXCallingConv_X86_64Win64
init|=
literal|10
block|,
name|CXCallingConv_X86_64SysV
init|=
literal|11
block|,
name|CXCallingConv_X86VectorCall
init|=
literal|12
block|,
name|CXCallingConv_Swift
init|=
literal|13
block|,
name|CXCallingConv_PreserveMost
init|=
literal|14
block|,
name|CXCallingConv_PreserveAll
init|=
literal|15
block|,
name|CXCallingConv_Invalid
init|=
literal|100
block|,
name|CXCallingConv_Unexposed
init|=
literal|200
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
comment|/**  * \brief Pretty-print the underlying type using the rules of the  * language of the translation unit from which it came.  *  * If the type is invalid, an empty string is returned.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_getTypeSpelling
parameter_list|(
name|CXType
name|CT
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the underlying type of a typedef declaration.  *  * If the cursor does not reference a typedef declaration, an invalid type is  * returned.  */
name|CINDEX_LINKAGE
name|CXType
name|clang_getTypedefDeclUnderlyingType
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the integer type of an enum declaration.  *  * If the cursor does not reference an enum declaration, an invalid type is  * returned.  */
name|CINDEX_LINKAGE
name|CXType
name|clang_getEnumDeclIntegerType
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the integer value of an enum constant declaration as a signed  *  long long.  *  * If the cursor does not reference an enum constant declaration, LLONG_MIN is returned.  * Since this is also potentially a valid constant value, the kind of the cursor  * must be verified before calling this function.  */
name|CINDEX_LINKAGE
name|long
name|long
name|clang_getEnumConstantDeclValue
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the integer value of an enum constant declaration as an unsigned  *  long long.  *  * If the cursor does not reference an enum constant declaration, ULLONG_MAX is returned.  * Since this is also potentially a valid constant value, the kind of the cursor  * must be verified before calling this function.  */
name|CINDEX_LINKAGE
name|unsigned
name|long
name|long
name|clang_getEnumConstantDeclUnsignedValue
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the bit width of a bit field declaration as an integer.  *  * If a cursor that is not a bit field declaration is passed in, -1 is returned.  */
name|CINDEX_LINKAGE
name|int
name|clang_getFieldDeclBitWidth
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the number of non-variadic arguments associated with a given  * cursor.  *  * The number of arguments can be determined for calls as well as for  * declarations of functions or methods. For other cursors -1 is returned.  */
name|CINDEX_LINKAGE
name|int
name|clang_Cursor_getNumArguments
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the argument cursor of a function or method.  *  * The argument cursor can be determined for calls as well as for declarations  * of functions or methods. For other cursors and for invalid indices, an  * invalid cursor is returned.  */
name|CINDEX_LINKAGE
name|CXCursor
name|clang_Cursor_getArgument
parameter_list|(
name|CXCursor
name|C
parameter_list|,
name|unsigned
name|i
parameter_list|)
function_decl|;
comment|/**  * \brief Describes the kind of a template argument.  *  * See the definition of llvm::clang::TemplateArgument::ArgKind for full  * element descriptions.  */
enum|enum
name|CXTemplateArgumentKind
block|{
name|CXTemplateArgumentKind_Null
block|,
name|CXTemplateArgumentKind_Type
block|,
name|CXTemplateArgumentKind_Declaration
block|,
name|CXTemplateArgumentKind_NullPtr
block|,
name|CXTemplateArgumentKind_Integral
block|,
name|CXTemplateArgumentKind_Template
block|,
name|CXTemplateArgumentKind_TemplateExpansion
block|,
name|CXTemplateArgumentKind_Expression
block|,
name|CXTemplateArgumentKind_Pack
block|,
comment|/* Indicates an error case, preventing the kind from being deduced. */
name|CXTemplateArgumentKind_Invalid
block|}
enum|;
comment|/**  *\brief Returns the number of template args of a function decl representing a  * template specialization.  *  * If the argument cursor cannot be converted into a template function  * declaration, -1 is returned.  *  * For example, for the following declaration and specialization:  *   template<typename T, int kInt, bool kBool>  *   void foo() { ... }  *  *   template<>  *   void foo<float, -7, true>();  *  * The value 3 would be returned from this call.  */
name|CINDEX_LINKAGE
name|int
name|clang_Cursor_getNumTemplateArguments
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the kind of the I'th template argument of the CXCursor C.  *  * If the argument CXCursor does not represent a FunctionDecl, an invalid  * template argument kind is returned.  *  * For example, for the following declaration and specialization:  *   template<typename T, int kInt, bool kBool>  *   void foo() { ... }  *  *   template<>  *   void foo<float, -7, true>();  *  * For I = 0, 1, and 2, Type, Integral, and Integral will be returned,  * respectively.  */
name|CINDEX_LINKAGE
name|enum
name|CXTemplateArgumentKind
name|clang_Cursor_getTemplateArgumentKind
parameter_list|(
name|CXCursor
name|C
parameter_list|,
name|unsigned
name|I
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve a CXType representing the type of a TemplateArgument of a  *  function decl representing a template specialization.  *  * If the argument CXCursor does not represent a FunctionDecl whose I'th  * template argument has a kind of CXTemplateArgKind_Integral, an invalid type  * is returned.  *  * For example, for the following declaration and specialization:  *   template<typename T, int kInt, bool kBool>  *   void foo() { ... }  *  *   template<>  *   void foo<float, -7, true>();  *  * If called with I = 0, "float", will be returned.  * Invalid types will be returned for I == 1 or 2.  */
name|CINDEX_LINKAGE
name|CXType
name|clang_Cursor_getTemplateArgumentType
parameter_list|(
name|CXCursor
name|C
parameter_list|,
name|unsigned
name|I
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the value of an Integral TemplateArgument (of a function  *  decl representing a template specialization) as a signed long long.  *  * It is undefined to call this function on a CXCursor that does not represent a  * FunctionDecl or whose I'th template argument is not an integral value.  *  * For example, for the following declaration and specialization:  *   template<typename T, int kInt, bool kBool>  *   void foo() { ... }  *  *   template<>  *   void foo<float, -7, true>();  *  * If called with I = 1 or 2, -7 or true will be returned, respectively.  * For I == 0, this function's behavior is undefined.  */
name|CINDEX_LINKAGE
name|long
name|long
name|clang_Cursor_getTemplateArgumentValue
parameter_list|(
name|CXCursor
name|C
parameter_list|,
name|unsigned
name|I
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the value of an Integral TemplateArgument (of a function  *  decl representing a template specialization) as an unsigned long long.  *  * It is undefined to call this function on a CXCursor that does not represent a  * FunctionDecl or whose I'th template argument is not an integral value.  *  * For example, for the following declaration and specialization:  *   template<typename T, int kInt, bool kBool>  *   void foo() { ... }  *  *   template<>  *   void foo<float, 2147483649, true>();  *  * If called with I = 1 or 2, 2147483649 or true will be returned, respectively.  * For I == 0, this function's behavior is undefined.  */
name|CINDEX_LINKAGE
name|unsigned
name|long
name|long
name|clang_Cursor_getTemplateArgumentUnsignedValue
parameter_list|(
name|CXCursor
name|C
parameter_list|,
name|unsigned
name|I
parameter_list|)
function_decl|;
comment|/**  * \brief Determine whether two CXTypes represent the same type.  *  * \returns non-zero if the CXTypes represent the same type and  *          zero otherwise.  */
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
comment|/**  * \brief Determine whether a CXType has the "const" qualifier set,  * without looking through typedefs that may have added "const" at a  * different level.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_isConstQualifiedType
parameter_list|(
name|CXType
name|T
parameter_list|)
function_decl|;
comment|/**  * \brief Determine whether a  CXCursor that is a macro, is  * function like.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_Cursor_isMacroFunctionLike
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * \brief Determine whether a  CXCursor that is a macro, is a  * builtin one.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_Cursor_isMacroBuiltin
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * \brief Determine whether a  CXCursor that is a function declaration, is an  * inline declaration.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_Cursor_isFunctionInlined
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * \brief Determine whether a CXType has the "volatile" qualifier set,  * without looking through typedefs that may have added "volatile" at  * a different level.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_isVolatileQualifiedType
parameter_list|(
name|CXType
name|T
parameter_list|)
function_decl|;
comment|/**  * \brief Determine whether a CXType has the "restrict" qualifier set,  * without looking through typedefs that may have added "restrict" at a  * different level.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_isRestrictQualifiedType
parameter_list|(
name|CXType
name|T
parameter_list|)
function_decl|;
comment|/**  * \brief For pointer types, returns the type of the pointee.  */
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
comment|/**  * Returns the Objective-C type encoding for the specified CXType.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_Type_getObjCEncoding
parameter_list|(
name|CXType
name|type
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
comment|/**  * \brief Retrieve the calling convention associated with a function type.  *  * If a non-function type is passed in, CXCallingConv_Invalid is returned.  */
name|CINDEX_LINKAGE
name|enum
name|CXCallingConv
name|clang_getFunctionTypeCallingConv
parameter_list|(
name|CXType
name|T
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the return type associated with a function type.  *  * If a non-function type is passed in, an invalid type is returned.  */
name|CINDEX_LINKAGE
name|CXType
name|clang_getResultType
parameter_list|(
name|CXType
name|T
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the number of non-variadic parameters associated with a  * function type.  *  * If a non-function type is passed in, -1 is returned.  */
name|CINDEX_LINKAGE
name|int
name|clang_getNumArgTypes
parameter_list|(
name|CXType
name|T
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the type of a parameter of a function type.  *  * If a non-function type is passed in or the function does not have enough  * parameters, an invalid type is returned.  */
name|CINDEX_LINKAGE
name|CXType
name|clang_getArgType
parameter_list|(
name|CXType
name|T
parameter_list|,
name|unsigned
name|i
parameter_list|)
function_decl|;
comment|/**  * \brief Return 1 if the CXType is a variadic function type, and 0 otherwise.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_isFunctionTypeVariadic
parameter_list|(
name|CXType
name|T
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the return type associated with a given cursor.  *  * This only returns a valid type if the cursor refers to a function or method.  */
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
comment|/**  * \brief Return the element type of an array, complex, or vector type.  *  * If a type is passed in that is not an array, complex, or vector type,  * an invalid type is returned.  */
name|CINDEX_LINKAGE
name|CXType
name|clang_getElementType
parameter_list|(
name|CXType
name|T
parameter_list|)
function_decl|;
comment|/**  * \brief Return the number of elements of an array or vector type.  *  * If a type is passed in that is not an array or vector type,  * -1 is returned.  */
name|CINDEX_LINKAGE
name|long
name|long
name|clang_getNumElements
parameter_list|(
name|CXType
name|T
parameter_list|)
function_decl|;
comment|/**  * \brief Return the element type of an array type.  *  * If a non-array type is passed in, an invalid type is returned.  */
name|CINDEX_LINKAGE
name|CXType
name|clang_getArrayElementType
parameter_list|(
name|CXType
name|T
parameter_list|)
function_decl|;
comment|/**  * \brief Return the array size of a constant array.  *  * If a non-array type is passed in, -1 is returned.  */
name|CINDEX_LINKAGE
name|long
name|long
name|clang_getArraySize
parameter_list|(
name|CXType
name|T
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the type named by the qualified-id.  *  * If a non-elaborated type is passed in, an invalid type is returned.  */
name|CINDEX_LINKAGE
name|CXType
name|clang_Type_getNamedType
parameter_list|(
name|CXType
name|T
parameter_list|)
function_decl|;
comment|/**  * \brief Determine if a typedef is 'transparent' tag.  *  * A typedef is considered 'transparent' if it shares a name and spelling  * location with its underlying tag type, as is the case with the NS_ENUM macro.  *  * \returns non-zero if transparent and zero otherwise.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_Type_isTransparentTagTypedef
parameter_list|(
name|CXType
name|T
parameter_list|)
function_decl|;
comment|/**  * \brief List the possible error codes for \c clang_Type_getSizeOf,  *   \c clang_Type_getAlignOf, \c clang_Type_getOffsetOf and  *   \c clang_Cursor_getOffsetOf.  *  * A value of this enumeration type can be returned if the target type is not  * a valid argument to sizeof, alignof or offsetof.  */
enum|enum
name|CXTypeLayoutError
block|{
comment|/**    * \brief Type is of kind CXType_Invalid.    */
name|CXTypeLayoutError_Invalid
init|=
operator|-
literal|1
block|,
comment|/**    * \brief The type is an incomplete Type.    */
name|CXTypeLayoutError_Incomplete
init|=
operator|-
literal|2
block|,
comment|/**    * \brief The type is a dependent Type.    */
name|CXTypeLayoutError_Dependent
init|=
operator|-
literal|3
block|,
comment|/**    * \brief The type is not a constant size type.    */
name|CXTypeLayoutError_NotConstantSize
init|=
operator|-
literal|4
block|,
comment|/**    * \brief The Field name is not valid for this record.    */
name|CXTypeLayoutError_InvalidFieldName
init|=
operator|-
literal|5
block|}
enum|;
comment|/**  * \brief Return the alignment of a type in bytes as per C++[expr.alignof]  *   standard.  *  * If the type declaration is invalid, CXTypeLayoutError_Invalid is returned.  * If the type declaration is an incomplete type, CXTypeLayoutError_Incomplete  *   is returned.  * If the type declaration is a dependent type, CXTypeLayoutError_Dependent is  *   returned.  * If the type declaration is not a constant size type,  *   CXTypeLayoutError_NotConstantSize is returned.  */
name|CINDEX_LINKAGE
name|long
name|long
name|clang_Type_getAlignOf
parameter_list|(
name|CXType
name|T
parameter_list|)
function_decl|;
comment|/**  * \brief Return the class type of an member pointer type.  *  * If a non-member-pointer type is passed in, an invalid type is returned.  */
name|CINDEX_LINKAGE
name|CXType
name|clang_Type_getClassType
parameter_list|(
name|CXType
name|T
parameter_list|)
function_decl|;
comment|/**  * \brief Return the size of a type in bytes as per C++[expr.sizeof] standard.  *  * If the type declaration is invalid, CXTypeLayoutError_Invalid is returned.  * If the type declaration is an incomplete type, CXTypeLayoutError_Incomplete  *   is returned.  * If the type declaration is a dependent type, CXTypeLayoutError_Dependent is  *   returned.  */
name|CINDEX_LINKAGE
name|long
name|long
name|clang_Type_getSizeOf
parameter_list|(
name|CXType
name|T
parameter_list|)
function_decl|;
comment|/**  * \brief Return the offset of a field named S in a record of type T in bits  *   as it would be returned by __offsetof__ as per C++11[18.2p4]  *  * If the cursor is not a record field declaration, CXTypeLayoutError_Invalid  *   is returned.  * If the field's type declaration is an incomplete type,  *   CXTypeLayoutError_Incomplete is returned.  * If the field's type declaration is a dependent type,  *   CXTypeLayoutError_Dependent is returned.  * If the field's name S is not found,  *   CXTypeLayoutError_InvalidFieldName is returned.  */
name|CINDEX_LINKAGE
name|long
name|long
name|clang_Type_getOffsetOf
parameter_list|(
name|CXType
name|T
parameter_list|,
specifier|const
name|char
modifier|*
name|S
parameter_list|)
function_decl|;
comment|/**  * \brief Return the offset of the field represented by the Cursor.  *  * If the cursor is not a field declaration, -1 is returned.  * If the cursor semantic parent is not a record field declaration,  *   CXTypeLayoutError_Invalid is returned.  * If the field's type declaration is an incomplete type,  *   CXTypeLayoutError_Incomplete is returned.  * If the field's type declaration is a dependent type,  *   CXTypeLayoutError_Dependent is returned.  * If the field's name S is not found,  *   CXTypeLayoutError_InvalidFieldName is returned.  */
name|CINDEX_LINKAGE
name|long
name|long
name|clang_Cursor_getOffsetOfField
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * \brief Determine whether the given cursor represents an anonymous record  * declaration.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_Cursor_isAnonymous
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
enum|enum
name|CXRefQualifierKind
block|{
comment|/** \brief No ref-qualifier was provided. */
name|CXRefQualifier_None
init|=
literal|0
block|,
comment|/** \brief An lvalue ref-qualifier was provided (\c&). */
name|CXRefQualifier_LValue
block|,
comment|/** \brief An rvalue ref-qualifier was provided (\c&&). */
name|CXRefQualifier_RValue
block|}
enum|;
comment|/**  * \brief Returns the number of template arguments for given template  * specialization, or -1 if type \c T is not a template specialization.  */
name|CINDEX_LINKAGE
name|int
name|clang_Type_getNumTemplateArguments
parameter_list|(
name|CXType
name|T
parameter_list|)
function_decl|;
comment|/**  * \brief Returns the type template argument of a template class specialization  * at given index.  *  * This function only returns template type arguments and does not handle  * template template arguments or variadic packs.  */
name|CINDEX_LINKAGE
name|CXType
name|clang_Type_getTemplateArgumentAsType
parameter_list|(
name|CXType
name|T
parameter_list|,
name|unsigned
name|i
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the ref-qualifier kind of a function or method.  *  * The ref-qualifier is returned for C++ functions or methods. For other types  * or non-C++ declarations, CXRefQualifier_None is returned.  */
name|CINDEX_LINKAGE
name|enum
name|CXRefQualifierKind
name|clang_Type_getCXXRefQualifier
parameter_list|(
name|CXType
name|T
parameter_list|)
function_decl|;
comment|/**  * \brief Returns non-zero if the cursor specifies a Record member that is a  *   bitfield.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_Cursor_isBitField
parameter_list|(
name|CXCursor
name|C
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
comment|/**  * \brief Returns the access control level for the referenced object.  *  * If the cursor refers to a C++ declaration, its access control level within its  * parent scope is returned. Otherwise, if the cursor refers to a base specifier or  * access specifier, the specifier itself is returned.  */
name|CINDEX_LINKAGE
name|enum
name|CX_CXXAccessSpecifier
name|clang_getCXXAccessSpecifier
parameter_list|(
name|CXCursor
parameter_list|)
function_decl|;
comment|/**  * \brief Represents the storage classes as declared in the source. CX_SC_Invalid  * was added for the case that the passed cursor in not a declaration.  */
enum|enum
name|CX_StorageClass
block|{
name|CX_SC_Invalid
block|,
name|CX_SC_None
block|,
name|CX_SC_Extern
block|,
name|CX_SC_Static
block|,
name|CX_SC_PrivateExtern
block|,
name|CX_SC_OpenCLWorkGroupLocal
block|,
name|CX_SC_Auto
block|,
name|CX_SC_Register
block|}
enum|;
comment|/**  * \brief Returns the storage class for a function or variable declaration.  *  * If the passed in Cursor is not a function or variable declaration,  * CX_SC_Invalid is returned else the storage class.  */
name|CINDEX_LINKAGE
name|enum
name|CX_StorageClass
name|clang_Cursor_getStorageClass
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
name|CINDEX_LINKAGE
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
comment|/**  * \brief Retrieve a range for a piece that forms the cursors spelling name.  * Most of the times there is only one range for the complete spelling but for  * Objective-C methods and Objective-C message expressions, there are multiple  * pieces for each selector identifier.  *   * \param pieceIndex the index of the spelling name piece. If this is greater  * than the actual number of pieces, it will return a NULL (invalid) range.  *    * \param options Reserved.  */
name|CINDEX_LINKAGE
name|CXSourceRange
name|clang_Cursor_getSpellingNameRange
parameter_list|(
name|CXCursor
parameter_list|,
name|unsigned
name|pieceIndex
parameter_list|,
name|unsigned
name|options
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
comment|/**  * \brief If the cursor points to a selector identifier in an Objective-C  * method or message expression, this returns the selector index.  *  * After getting a cursor with #clang_getCursor, this can be called to  * determine if the location points to a selector identifier.  *  * \returns The selector index if the cursor is an Objective-C method or message  * expression and the cursor is pointing to a selector identifier, or -1  * otherwise.  */
name|CINDEX_LINKAGE
name|int
name|clang_Cursor_getObjCSelectorIndex
parameter_list|(
name|CXCursor
parameter_list|)
function_decl|;
comment|/**  * \brief Given a cursor pointing to a C++ method call or an Objective-C  * message, returns non-zero if the method/message is "dynamic", meaning:  *   * For a C++ method: the call is virtual.  * For an Objective-C message: the receiver is an object instance, not 'super'  * or a specific class.  *   * If the method/message is "static" or the cursor does not point to a  * method/message, it will return zero.  */
name|CINDEX_LINKAGE
name|int
name|clang_Cursor_isDynamicCall
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * \brief Given a cursor pointing to an Objective-C message or property  * reference, or C++ method call, returns the CXType of the receiver.  */
name|CINDEX_LINKAGE
name|CXType
name|clang_Cursor_getReceiverType
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * \brief Property attributes for a \c CXCursor_ObjCPropertyDecl.  */
typedef|typedef
enum|enum
block|{
name|CXObjCPropertyAttr_noattr
init|=
literal|0x00
block|,
name|CXObjCPropertyAttr_readonly
init|=
literal|0x01
block|,
name|CXObjCPropertyAttr_getter
init|=
literal|0x02
block|,
name|CXObjCPropertyAttr_assign
init|=
literal|0x04
block|,
name|CXObjCPropertyAttr_readwrite
init|=
literal|0x08
block|,
name|CXObjCPropertyAttr_retain
init|=
literal|0x10
block|,
name|CXObjCPropertyAttr_copy
init|=
literal|0x20
block|,
name|CXObjCPropertyAttr_nonatomic
init|=
literal|0x40
block|,
name|CXObjCPropertyAttr_setter
init|=
literal|0x80
block|,
name|CXObjCPropertyAttr_atomic
init|=
literal|0x100
block|,
name|CXObjCPropertyAttr_weak
init|=
literal|0x200
block|,
name|CXObjCPropertyAttr_strong
init|=
literal|0x400
block|,
name|CXObjCPropertyAttr_unsafe_unretained
init|=
literal|0x800
block|,
name|CXObjCPropertyAttr_class
init|=
literal|0x1000
block|}
name|CXObjCPropertyAttrKind
typedef|;
comment|/**  * \brief Given a cursor that represents a property declaration, return the  * associated property attributes. The bits are formed from  * \c CXObjCPropertyAttrKind.  *  * \param reserved Reserved for future use, pass 0.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_Cursor_getObjCPropertyAttributes
parameter_list|(
name|CXCursor
name|C
parameter_list|,
name|unsigned
name|reserved
parameter_list|)
function_decl|;
comment|/**  * \brief 'Qualifiers' written next to the return and parameter types in  * Objective-C method declarations.  */
typedef|typedef
enum|enum
block|{
name|CXObjCDeclQualifier_None
init|=
literal|0x0
block|,
name|CXObjCDeclQualifier_In
init|=
literal|0x1
block|,
name|CXObjCDeclQualifier_Inout
init|=
literal|0x2
block|,
name|CXObjCDeclQualifier_Out
init|=
literal|0x4
block|,
name|CXObjCDeclQualifier_Bycopy
init|=
literal|0x8
block|,
name|CXObjCDeclQualifier_Byref
init|=
literal|0x10
block|,
name|CXObjCDeclQualifier_Oneway
init|=
literal|0x20
block|}
name|CXObjCDeclQualifierKind
typedef|;
comment|/**  * \brief Given a cursor that represents an Objective-C method or parameter  * declaration, return the associated Objective-C qualifiers for the return  * type or the parameter respectively. The bits are formed from  * CXObjCDeclQualifierKind.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_Cursor_getObjCDeclQualifiers
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * \brief Given a cursor that represents an Objective-C method or property  * declaration, return non-zero if the declaration was affected by "\@optional".  * Returns zero if the cursor is not such a declaration or it is "\@required".  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_Cursor_isObjCOptional
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * \brief Returns non-zero if the given cursor is a variadic function or method.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_Cursor_isVariadic
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * \brief Given a cursor that represents a declaration, return the associated  * comment's source range.  The range may include multiple consecutive comments  * with whitespace in between.  */
name|CINDEX_LINKAGE
name|CXSourceRange
name|clang_Cursor_getCommentRange
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * \brief Given a cursor that represents a declaration, return the associated  * comment text, including comment markers.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_Cursor_getRawCommentText
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * \brief Given a cursor that represents a documentable entity (e.g.,  * declaration), return the associated \\brief paragraph; otherwise return the  * first paragraph.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_Cursor_getBriefCommentText
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * @}  */
comment|/** \defgroup CINDEX_MANGLE Name Mangling API Functions  *  * @{  */
comment|/**  * \brief Retrieve the CXString representing the mangled name of the cursor.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_Cursor_getMangling
parameter_list|(
name|CXCursor
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the CXStrings representing the mangled symbols of the C++  * constructor or destructor at the cursor.  */
name|CINDEX_LINKAGE
name|CXStringSet
modifier|*
name|clang_Cursor_getCXXManglings
parameter_list|(
name|CXCursor
parameter_list|)
function_decl|;
comment|/**  * @}  */
comment|/**  * \defgroup CINDEX_MODULE Module introspection  *  * The functions in this group provide access to information about modules.  *  * @{  */
typedef|typedef
name|void
modifier|*
name|CXModule
typedef|;
comment|/**  * \brief Given a CXCursor_ModuleImportDecl cursor, return the associated module.  */
name|CINDEX_LINKAGE
name|CXModule
name|clang_Cursor_getModule
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * \brief Given a CXFile header file, return the module that contains it, if one  * exists.  */
name|CINDEX_LINKAGE
name|CXModule
name|clang_getModuleForFile
parameter_list|(
name|CXTranslationUnit
parameter_list|,
name|CXFile
parameter_list|)
function_decl|;
comment|/**  * \param Module a module object.  *  * \returns the module file where the provided module object came from.  */
name|CINDEX_LINKAGE
name|CXFile
name|clang_Module_getASTFile
parameter_list|(
name|CXModule
name|Module
parameter_list|)
function_decl|;
comment|/**  * \param Module a module object.  *  * \returns the parent of a sub-module or NULL if the given module is top-level,  * e.g. for 'std.vector' it will return the 'std' module.  */
name|CINDEX_LINKAGE
name|CXModule
name|clang_Module_getParent
parameter_list|(
name|CXModule
name|Module
parameter_list|)
function_decl|;
comment|/**  * \param Module a module object.  *  * \returns the name of the module, e.g. for the 'std.vector' sub-module it  * will return "vector".  */
name|CINDEX_LINKAGE
name|CXString
name|clang_Module_getName
parameter_list|(
name|CXModule
name|Module
parameter_list|)
function_decl|;
comment|/**  * \param Module a module object.  *  * \returns the full name of the module, e.g. "std.vector".  */
name|CINDEX_LINKAGE
name|CXString
name|clang_Module_getFullName
parameter_list|(
name|CXModule
name|Module
parameter_list|)
function_decl|;
comment|/**  * \param Module a module object.  *  * \returns non-zero if the module is a system one.  */
name|CINDEX_LINKAGE
name|int
name|clang_Module_isSystem
parameter_list|(
name|CXModule
name|Module
parameter_list|)
function_decl|;
comment|/**  * \param Module a module object.  *  * \returns the number of top level headers associated with this module.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_Module_getNumTopLevelHeaders
parameter_list|(
name|CXTranslationUnit
parameter_list|,
name|CXModule
name|Module
parameter_list|)
function_decl|;
comment|/**  * \param Module a module object.  *  * \param Index top level header index (zero-based).  *  * \returns the specified top level header associated with the module.  */
name|CINDEX_LINKAGE
name|CXFile
name|clang_Module_getTopLevelHeader
parameter_list|(
name|CXTranslationUnit
parameter_list|,
name|CXModule
name|Module
parameter_list|,
name|unsigned
name|Index
parameter_list|)
function_decl|;
comment|/**  * @}  */
comment|/**  * \defgroup CINDEX_CPP C++ AST introspection  *  * The routines in this group provide access information in the ASTs specific  * to C++ language features.  *  * @{  */
comment|/**  * \brief Determine if a C++ constructor is a converting constructor.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_CXXConstructor_isConvertingConstructor
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * \brief Determine if a C++ constructor is a copy constructor.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_CXXConstructor_isCopyConstructor
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * \brief Determine if a C++ constructor is the default constructor.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_CXXConstructor_isDefaultConstructor
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * \brief Determine if a C++ constructor is a move constructor.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_CXXConstructor_isMoveConstructor
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * \brief Determine if a C++ field is declared 'mutable'.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_CXXField_isMutable
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * \brief Determine if a C++ method is declared '= default'.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_CXXMethod_isDefaulted
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * \brief Determine if a C++ member function or member function template is  * pure virtual.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_CXXMethod_isPureVirtual
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * \brief Determine if a C++ member function or member function template is   * declared 'static'.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_CXXMethod_isStatic
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * \brief Determine if a C++ member function or member function template is  * explicitly declared 'virtual' or if it overrides a virtual method from  * one of the base classes.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_CXXMethod_isVirtual
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * \brief Determine if a C++ member function or member function template is  * declared 'const'.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_CXXMethod_isConst
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
comment|/**  * \brief Given a cursor that references something else, return the source range  * covering that reference.  *  * \param C A cursor pointing to a member reference, a declaration reference, or  * an operator call.  * \param NameFlags A bitset with three independent flags:   * CXNameRange_WantQualifier, CXNameRange_WantTemplateArgs, and  * CXNameRange_WantSinglePiece.  * \param PieceIndex For contiguous names or when passing the flag   * CXNameRange_WantSinglePiece, only one piece with index 0 is   * available. When the CXNameRange_WantSinglePiece flag is not passed for a  * non-contiguous names, this index can be used to retrieve the individual  * pieces of the name. See also CXNameRange_WantSinglePiece.  *  * \returns The piece of the name pointed to by the given cursor. If there is no  * name, or if the PieceIndex is out-of-range, a null-cursor will be returned.  */
name|CINDEX_LINKAGE
name|CXSourceRange
name|clang_getCursorReferenceNameRange
parameter_list|(
name|CXCursor
name|C
parameter_list|,
name|unsigned
name|NameFlags
parameter_list|,
name|unsigned
name|PieceIndex
parameter_list|)
function_decl|;
enum|enum
name|CXNameRefFlags
block|{
comment|/**    * \brief Include the nested-name-specifier, e.g. Foo:: in x.Foo::y, in the    * range.    */
name|CXNameRange_WantQualifier
init|=
literal|0x1
block|,
comment|/**    * \brief Include the explicit template arguments, e.g. \<int> in x.f<int>,    * in the range.    */
name|CXNameRange_WantTemplateArgs
init|=
literal|0x2
block|,
comment|/**    * \brief If the name is non-contiguous, return the full spanning range.    *    * Non-contiguous names occur in Objective-C when a selector with two or more    * parameters is used, or in C++ when using an operator:    * \code    * [object doSomething:here withValue:there]; // Objective-C    * return some_vector[1]; // C++    * \endcode    */
name|CXNameRange_WantSinglePiece
init|=
literal|0x4
block|}
enum|;
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
comment|/**    * Vertical space ('\\n'), after which it is generally a good idea to    * perform indentation.    */
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
comment|/**  * \brief Retrieve the completion string associated with a particular chunk  * within a completion string.  *  * \param completion_string the completion string to query.  *  * \param chunk_number the 0-based index of the chunk in the completion string.  *  * \returns the completion string associated with the chunk at index  * \c chunk_number.  */
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
comment|/**  * \brief Retrieve the number of annotations associated with the given  * completion string.  *  * \param completion_string the completion string to query.  *  * \returns the number of annotations associated with the given completion  * string.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_getCompletionNumAnnotations
parameter_list|(
name|CXCompletionString
name|completion_string
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the annotation associated with the given completion string.  *  * \param completion_string the completion string to query.  *  * \param annotation_number the 0-based index of the annotation of the  * completion string.  *  * \returns annotation string associated with the completion at index  * \c annotation_number, or a NULL string if that annotation is not available.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_getCompletionAnnotation
parameter_list|(
name|CXCompletionString
name|completion_string
parameter_list|,
name|unsigned
name|annotation_number
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the parent context of the given completion string.  *  * The parent context of a completion string is the semantic parent of   * the declaration (if any) that the code completion represents. For example,  * a code completion for an Objective-C method would have the method's class  * or protocol as its context.  *  * \param completion_string The code completion string whose parent is  * being queried.  *  * \param kind DEPRECATED: always set to CXCursor_NotImplemented if non-NULL.  *  * \returns The name of the completion parent, e.g., "NSObject" if  * the completion string represents a method in the NSObject class.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_getCompletionParent
parameter_list|(
name|CXCompletionString
name|completion_string
parameter_list|,
name|enum
name|CXCursorKind
modifier|*
name|kind
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the brief documentation comment attached to the declaration  * that corresponds to the given completion string.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_getCompletionBriefComment
parameter_list|(
name|CXCompletionString
name|completion_string
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve a completion string for an arbitrary declaration or macro  * definition cursor.  *  * \param cursor The cursor to query.  *  * \returns A non-context-sensitive completion string for declaration and macro  * definition cursors, or NULL for other kinds of cursors.  */
name|CINDEX_LINKAGE
name|CXCompletionString
name|clang_getCursorCompletionString
parameter_list|(
name|CXCursor
name|cursor
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
block|,
comment|/**    * \brief Whether to include brief documentation within the set of code    * completions returned.    */
name|CXCodeComplete_IncludeBriefComments
init|=
literal|0x04
block|}
enum|;
comment|/**  * \brief Bits that represent the context under which completion is occurring.  *  * The enumerators in this enumeration may be bitwise-OR'd together if multiple  * contexts are occurring simultaneously.  */
enum|enum
name|CXCompletionContext
block|{
comment|/**    * \brief The context for completions is unexposed, as only Clang results    * should be included. (This is equivalent to having no context bits set.)    */
name|CXCompletionContext_Unexposed
init|=
literal|0
block|,
comment|/**    * \brief Completions for any possible type should be included in the results.    */
name|CXCompletionContext_AnyType
init|=
literal|1
operator|<<
literal|0
block|,
comment|/**    * \brief Completions for any possible value (variables, function calls, etc.)    * should be included in the results.    */
name|CXCompletionContext_AnyValue
init|=
literal|1
operator|<<
literal|1
block|,
comment|/**    * \brief Completions for values that resolve to an Objective-C object should    * be included in the results.    */
name|CXCompletionContext_ObjCObjectValue
init|=
literal|1
operator|<<
literal|2
block|,
comment|/**    * \brief Completions for values that resolve to an Objective-C selector    * should be included in the results.    */
name|CXCompletionContext_ObjCSelectorValue
init|=
literal|1
operator|<<
literal|3
block|,
comment|/**    * \brief Completions for values that resolve to a C++ class type should be    * included in the results.    */
name|CXCompletionContext_CXXClassTypeValue
init|=
literal|1
operator|<<
literal|4
block|,
comment|/**    * \brief Completions for fields of the member being accessed using the dot    * operator should be included in the results.    */
name|CXCompletionContext_DotMemberAccess
init|=
literal|1
operator|<<
literal|5
block|,
comment|/**    * \brief Completions for fields of the member being accessed using the arrow    * operator should be included in the results.    */
name|CXCompletionContext_ArrowMemberAccess
init|=
literal|1
operator|<<
literal|6
block|,
comment|/**    * \brief Completions for properties of the Objective-C object being accessed    * using the dot operator should be included in the results.    */
name|CXCompletionContext_ObjCPropertyAccess
init|=
literal|1
operator|<<
literal|7
block|,
comment|/**    * \brief Completions for enum tags should be included in the results.    */
name|CXCompletionContext_EnumTag
init|=
literal|1
operator|<<
literal|8
block|,
comment|/**    * \brief Completions for union tags should be included in the results.    */
name|CXCompletionContext_UnionTag
init|=
literal|1
operator|<<
literal|9
block|,
comment|/**    * \brief Completions for struct tags should be included in the results.    */
name|CXCompletionContext_StructTag
init|=
literal|1
operator|<<
literal|10
block|,
comment|/**    * \brief Completions for C++ class names should be included in the results.    */
name|CXCompletionContext_ClassTag
init|=
literal|1
operator|<<
literal|11
block|,
comment|/**    * \brief Completions for C++ namespaces and namespace aliases should be    * included in the results.    */
name|CXCompletionContext_Namespace
init|=
literal|1
operator|<<
literal|12
block|,
comment|/**    * \brief Completions for C++ nested name specifiers should be included in    * the results.    */
name|CXCompletionContext_NestedNameSpecifier
init|=
literal|1
operator|<<
literal|13
block|,
comment|/**    * \brief Completions for Objective-C interfaces (classes) should be included    * in the results.    */
name|CXCompletionContext_ObjCInterface
init|=
literal|1
operator|<<
literal|14
block|,
comment|/**    * \brief Completions for Objective-C protocols should be included in    * the results.    */
name|CXCompletionContext_ObjCProtocol
init|=
literal|1
operator|<<
literal|15
block|,
comment|/**    * \brief Completions for Objective-C categories should be included in    * the results.    */
name|CXCompletionContext_ObjCCategory
init|=
literal|1
operator|<<
literal|16
block|,
comment|/**    * \brief Completions for Objective-C instance messages should be included    * in the results.    */
name|CXCompletionContext_ObjCInstanceMessage
init|=
literal|1
operator|<<
literal|17
block|,
comment|/**    * \brief Completions for Objective-C class messages should be included in    * the results.    */
name|CXCompletionContext_ObjCClassMessage
init|=
literal|1
operator|<<
literal|18
block|,
comment|/**    * \brief Completions for Objective-C selector names should be included in    * the results.    */
name|CXCompletionContext_ObjCSelectorName
init|=
literal|1
operator|<<
literal|19
block|,
comment|/**    * \brief Completions for preprocessor macro names should be included in    * the results.    */
name|CXCompletionContext_MacroName
init|=
literal|1
operator|<<
literal|20
block|,
comment|/**    * \brief Natural language completions should be included in the results.    */
name|CXCompletionContext_NaturalLanguage
init|=
literal|1
operator|<<
literal|21
block|,
comment|/**    * \brief The current context is unknown, so set all contexts.    */
name|CXCompletionContext_Unknown
init|=
operator|(
operator|(
literal|1
operator|<<
literal|22
operator|)
operator|-
literal|1
operator|)
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
comment|/**  * \brief Perform code completion at a given location in a translation unit.  *  * This function performs code completion at a particular file, line, and  * column within source code, providing results that suggest potential  * code snippets based on the context of the completion. The basic model  * for code completion is that Clang will parse a complete source file,  * performing syntax checking up to the location where code-completion has  * been requested. At that point, a special code-completion token is passed  * to the parser, which recognizes this token and determines, based on the  * current location in the C/Objective-C/C++ grammar and the state of  * semantic analysis, what completions to provide. These completions are  * returned via a new \c CXCodeCompleteResults structure.  *  * Code completion itself is meant to be triggered by the client when the  * user types punctuation characters or whitespace, at which point the  * code-completion location will coincide with the cursor. For example, if \c p  * is a pointer, code-completion might be triggered after the "-" and then  * after the ">" in \c p->. When the code-completion location is afer the ">",  * the completion results will provide, e.g., the members of the struct that  * "p" points to. The client is responsible for placing the cursor at the  * beginning of the token currently being typed, then filtering the results  * based on the contents of the token. For example, when code-completing for  * the expression \c p->get, the client should provide the location just after  * the ">" (e.g., pointing at the "g") to this code-completion hook. Then, the  * client can filter the results based on the current token text ("get"), only  * showing those results that start with "get". The intent of this interface  * is to separate the relatively high-latency acquisition of code-completion  * results from the filtering of results on a per-character basis, which must  * have a lower latency.  *  * \param TU The translation unit in which code-completion should  * occur. The source files for this translation unit need not be  * completely up-to-date (and the contents of those source files may  * be overridden via \p unsaved_files). Cursors referring into the  * translation unit may be invalidated by this invocation.  *  * \param complete_filename The name of the source file where code  * completion should be performed. This filename may be any file  * included in the translation unit.  *  * \param complete_line The line at which code-completion should occur.  *  * \param complete_column The column at which code-completion should occur.  * Note that the column should point just after the syntactic construct that  * initiated code completion, and not in the middle of a lexical token.  *  * \param unsaved_files the Files that have not yet been saved to disk  * but may be required for parsing or code completion, including the  * contents of those files.  The contents and name of these files (as  * specified by CXUnsavedFile) are copied when necessary, so the  * client only needs to guarantee their validity until the call to  * this function returns.  *  * \param num_unsaved_files The number of unsaved file entries in \p  * unsaved_files.  *  * \param options Extra options that control the behavior of code  * completion, expressed as a bitwise OR of the enumerators of the  * CXCodeComplete_Flags enumeration. The   * \c clang_defaultCodeCompleteOptions() function returns a default set  * of code-completion options.  *  * \returns If successful, a new \c CXCodeCompleteResults structure  * containing code-completion results, which should eventually be  * freed with \c clang_disposeCodeCompleteResults(). If code  * completion fails, returns NULL.  */
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
comment|/**  * \brief Retrieve a diagnostic associated with the given code completion.  *  * \param Results the code completion results to query.  * \param Index the zero-based diagnostic number to retrieve.  *  * \returns the requested diagnostic. This diagnostic must be freed  * via a call to \c clang_disposeDiagnostic().  */
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
comment|/**  * \brief Determines what completions are appropriate for the context  * the given code completion.  *   * \param Results the code completion results to query  *  * \returns the kinds of completions that are appropriate for use  * along with the given code completion results.  */
name|CINDEX_LINKAGE
name|unsigned
name|long
name|long
name|clang_codeCompleteGetContexts
parameter_list|(
name|CXCodeCompleteResults
modifier|*
name|Results
parameter_list|)
function_decl|;
comment|/**  * \brief Returns the cursor kind for the container for the current code  * completion context. The container is only guaranteed to be set for  * contexts where a container exists (i.e. member accesses or Objective-C  * message sends); if there is not a container, this function will return  * CXCursor_InvalidCode.  *  * \param Results the code completion results to query  *  * \param IsIncomplete on return, this value will be false if Clang has complete  * information about the container. If Clang does not have complete  * information, this value will be true.  *  * \returns the container kind, or CXCursor_InvalidCode if there is not a  * container  */
name|CINDEX_LINKAGE
name|enum
name|CXCursorKind
name|clang_codeCompleteGetContainerKind
parameter_list|(
name|CXCodeCompleteResults
modifier|*
name|Results
parameter_list|,
name|unsigned
modifier|*
name|IsIncomplete
parameter_list|)
function_decl|;
comment|/**  * \brief Returns the USR for the container for the current code completion  * context. If there is not a container for the current context, this  * function will return the empty string.  *  * \param Results the code completion results to query  *  * \returns the USR for the container  */
name|CINDEX_LINKAGE
name|CXString
name|clang_codeCompleteGetContainerUSR
parameter_list|(
name|CXCodeCompleteResults
modifier|*
name|Results
parameter_list|)
function_decl|;
comment|/**  * \brief Returns the currently-entered selector for an Objective-C message  * send, formatted like "initWithFoo:bar:". Only guaranteed to return a  * non-empty string for CXCompletionContext_ObjCInstanceMessage and  * CXCompletionContext_ObjCClassMessage.  *  * \param Results the code completion results to query  *  * \returns the selector (or partial selector) that has been entered thus far  * for an Objective-C message send.  */
name|CINDEX_LINKAGE
name|CXString
name|clang_codeCompleteGetObjCSelector
parameter_list|(
name|CXCodeCompleteResults
modifier|*
name|Results
parameter_list|)
function_decl|;
comment|/**  * @}  */
comment|/**  * \defgroup CINDEX_MISC Miscellaneous utility functions  *  * @{  */
comment|/**  * \brief Return a version string, suitable for showing to a user, but not  *        intended to be parsed (the format is not guaranteed to be stable).  */
name|CINDEX_LINKAGE
name|CXString
name|clang_getClangVersion
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * \brief Enable/disable crash recovery.  *  * \param isEnabled Flag to indicate if crash recovery is enabled.  A non-zero  *        value enables crash recovery, while 0 disables it.  */
name|CINDEX_LINKAGE
name|void
name|clang_toggleCrashRecovery
parameter_list|(
name|unsigned
name|isEnabled
parameter_list|)
function_decl|;
comment|/**   * \brief Visitor invoked for each file in a translation unit   *        (used with clang_getInclusions()).   *   * This visitor function will be invoked by clang_getInclusions() for each   * file included (either at the top-level or by \#include directives) within   * a translation unit.  The first argument is the file being included, and   * the second and third arguments provide the inclusion stack.  The   * array is sorted in order of immediate inclusion.  For example,   * the first element refers to the location that included 'included_file'.   */
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
typedef|typedef
enum|enum
block|{
name|CXEval_Int
init|=
literal|1
block|,
name|CXEval_Float
init|=
literal|2
block|,
name|CXEval_ObjCStrLiteral
init|=
literal|3
block|,
name|CXEval_StrLiteral
init|=
literal|4
block|,
name|CXEval_CFStr
init|=
literal|5
block|,
name|CXEval_Other
init|=
literal|6
block|,
name|CXEval_UnExposed
init|=
literal|0
block|}
name|CXEvalResultKind
typedef|;
comment|/**  * \brief Evaluation result of a cursor  */
typedef|typedef
name|void
modifier|*
name|CXEvalResult
typedef|;
comment|/**  * \brief If cursor is a statement declaration tries to evaluate the   * statement and if its variable, tries to evaluate its initializer,  * into its corresponding type.  */
name|CINDEX_LINKAGE
name|CXEvalResult
name|clang_Cursor_Evaluate
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/**  * \brief Returns the kind of the evaluated result.  */
name|CINDEX_LINKAGE
name|CXEvalResultKind
name|clang_EvalResult_getKind
parameter_list|(
name|CXEvalResult
name|E
parameter_list|)
function_decl|;
comment|/**  * \brief Returns the evaluation result as integer if the  * kind is Int.  */
name|CINDEX_LINKAGE
name|int
name|clang_EvalResult_getAsInt
parameter_list|(
name|CXEvalResult
name|E
parameter_list|)
function_decl|;
comment|/**  * \brief Returns the evaluation result as a long long integer if the  * kind is Int. This prevents overflows that may happen if the result is  * returned with clang_EvalResult_getAsInt.  */
name|CINDEX_LINKAGE
name|long
name|long
name|clang_EvalResult_getAsLongLong
parameter_list|(
name|CXEvalResult
name|E
parameter_list|)
function_decl|;
comment|/**  * \brief Returns a non-zero value if the kind is Int and the evaluation  * result resulted in an unsigned integer.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_EvalResult_isUnsignedInt
parameter_list|(
name|CXEvalResult
name|E
parameter_list|)
function_decl|;
comment|/**  * \brief Returns the evaluation result as an unsigned integer if  * the kind is Int and clang_EvalResult_isUnsignedInt is non-zero.  */
name|CINDEX_LINKAGE
name|unsigned
name|long
name|long
name|clang_EvalResult_getAsUnsigned
parameter_list|(
name|CXEvalResult
name|E
parameter_list|)
function_decl|;
comment|/**  * \brief Returns the evaluation result as double if the  * kind is double.  */
name|CINDEX_LINKAGE
name|double
name|clang_EvalResult_getAsDouble
parameter_list|(
name|CXEvalResult
name|E
parameter_list|)
function_decl|;
comment|/**  * \brief Returns the evaluation result as a constant string if the  * kind is other than Int or float. User must not free this pointer,  * instead call clang_EvalResult_dispose on the CXEvalResult returned  * by clang_Cursor_Evaluate.  */
name|CINDEX_LINKAGE
specifier|const
name|char
modifier|*
name|clang_EvalResult_getAsStr
parameter_list|(
name|CXEvalResult
name|E
parameter_list|)
function_decl|;
comment|/**  * \brief Disposes the created Eval memory.  */
name|CINDEX_LINKAGE
name|void
name|clang_EvalResult_dispose
parameter_list|(
name|CXEvalResult
name|E
parameter_list|)
function_decl|;
comment|/**  * @}  */
comment|/** \defgroup CINDEX_REMAPPING Remapping functions  *  * @{  */
comment|/**  * \brief A remapping of original source files and their translated files.  */
typedef|typedef
name|void
modifier|*
name|CXRemapping
typedef|;
comment|/**  * \brief Retrieve a remapping.  *  * \param path the path that contains metadata about remappings.  *  * \returns the requested remapping. This remapping must be freed  * via a call to \c clang_remap_dispose(). Can return NULL if an error occurred.  */
name|CINDEX_LINKAGE
name|CXRemapping
name|clang_getRemappings
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve a remapping.  *  * \param filePaths pointer to an array of file paths containing remapping info.  *  * \param numFiles number of file paths.  *  * \returns the requested remapping. This remapping must be freed  * via a call to \c clang_remap_dispose(). Can return NULL if an error occurred.  */
name|CINDEX_LINKAGE
name|CXRemapping
name|clang_getRemappingsFromFileList
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|filePaths
parameter_list|,
name|unsigned
name|numFiles
parameter_list|)
function_decl|;
comment|/**  * \brief Determine the number of remappings.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_remap_getNumFiles
parameter_list|(
name|CXRemapping
parameter_list|)
function_decl|;
comment|/**  * \brief Get the original and the associated filename from the remapping.  *   * \param original If non-NULL, will be set to the original filename.  *  * \param transformed If non-NULL, will be set to the filename that the original  * is associated with.  */
name|CINDEX_LINKAGE
name|void
name|clang_remap_getFilenames
parameter_list|(
name|CXRemapping
parameter_list|,
name|unsigned
name|index
parameter_list|,
name|CXString
modifier|*
name|original
parameter_list|,
name|CXString
modifier|*
name|transformed
parameter_list|)
function_decl|;
comment|/**  * \brief Dispose the remapping.  */
name|CINDEX_LINKAGE
name|void
name|clang_remap_dispose
parameter_list|(
name|CXRemapping
parameter_list|)
function_decl|;
comment|/**  * @}  */
comment|/** \defgroup CINDEX_HIGH Higher level API functions  *  * @{  */
enum|enum
name|CXVisitorResult
block|{
name|CXVisit_Break
block|,
name|CXVisit_Continue
block|}
enum|;
typedef|typedef
struct|struct
name|CXCursorAndRangeVisitor
block|{
name|void
modifier|*
name|context
decl_stmt|;
name|enum
name|CXVisitorResult
function_decl|(
modifier|*
name|visit
function_decl|)
parameter_list|(
name|void
modifier|*
name|context
parameter_list|,
name|CXCursor
parameter_list|,
name|CXSourceRange
parameter_list|)
function_decl|;
block|}
name|CXCursorAndRangeVisitor
typedef|;
typedef|typedef
enum|enum
block|{
comment|/**    * \brief Function returned successfully.    */
name|CXResult_Success
init|=
literal|0
block|,
comment|/**    * \brief One of the parameters was invalid for the function.    */
name|CXResult_Invalid
init|=
literal|1
block|,
comment|/**    * \brief The function was terminated by a callback (e.g. it returned    * CXVisit_Break)    */
name|CXResult_VisitBreak
init|=
literal|2
block|}
name|CXResult
typedef|;
comment|/**  * \brief Find references of a declaration in a specific file.  *   * \param cursor pointing to a declaration or a reference of one.  *  * \param file to search for references.  *  * \param visitor callback that will receive pairs of CXCursor/CXSourceRange for  * each reference found.  * The CXSourceRange will point inside the file; if the reference is inside  * a macro (and not a macro argument) the CXSourceRange will be invalid.  *  * \returns one of the CXResult enumerators.  */
name|CINDEX_LINKAGE
name|CXResult
name|clang_findReferencesInFile
parameter_list|(
name|CXCursor
name|cursor
parameter_list|,
name|CXFile
name|file
parameter_list|,
name|CXCursorAndRangeVisitor
name|visitor
parameter_list|)
function_decl|;
comment|/**  * \brief Find #import/#include directives in a specific file.  *  * \param TU translation unit containing the file to query.  *  * \param file to search for #import/#include directives.  *  * \param visitor callback that will receive pairs of CXCursor/CXSourceRange for  * each directive found.  *  * \returns one of the CXResult enumerators.  */
name|CINDEX_LINKAGE
name|CXResult
name|clang_findIncludesInFile
parameter_list|(
name|CXTranslationUnit
name|TU
parameter_list|,
name|CXFile
name|file
parameter_list|,
name|CXCursorAndRangeVisitor
name|visitor
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
typedef|typedef
name|enum
name|CXVisitorResult
function_decl|(
modifier|^
name|CXCursorAndRangeVisitorBlock
function_decl|)
parameter_list|(
name|CXCursor
parameter_list|,
name|CXSourceRange
parameter_list|)
function_decl|;
name|CINDEX_LINKAGE
name|CXResult
name|clang_findReferencesInFileWithBlock
parameter_list|(
name|CXCursor
parameter_list|,
name|CXFile
parameter_list|,
name|CXCursorAndRangeVisitorBlock
parameter_list|)
function_decl|;
name|CINDEX_LINKAGE
name|CXResult
name|clang_findIncludesInFileWithBlock
parameter_list|(
name|CXTranslationUnit
parameter_list|,
name|CXFile
parameter_list|,
name|CXCursorAndRangeVisitorBlock
parameter_list|)
function_decl|;
endif|#
directive|endif
endif|#
directive|endif
comment|/**  * \brief The client's data object that is associated with a CXFile.  */
typedef|typedef
name|void
modifier|*
name|CXIdxClientFile
typedef|;
comment|/**  * \brief The client's data object that is associated with a semantic entity.  */
typedef|typedef
name|void
modifier|*
name|CXIdxClientEntity
typedef|;
comment|/**  * \brief The client's data object that is associated with a semantic container  * of entities.  */
typedef|typedef
name|void
modifier|*
name|CXIdxClientContainer
typedef|;
comment|/**  * \brief The client's data object that is associated with an AST file (PCH  * or module).  */
typedef|typedef
name|void
modifier|*
name|CXIdxClientASTFile
typedef|;
comment|/**  * \brief Source location passed to index callbacks.  */
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
name|CXIdxLoc
typedef|;
comment|/**  * \brief Data for ppIncludedFile callback.  */
typedef|typedef
struct|struct
block|{
comment|/**    * \brief Location of '#' in the \#include/\#import directive.    */
name|CXIdxLoc
name|hashLoc
decl_stmt|;
comment|/**    * \brief Filename as written in the \#include/\#import directive.    */
specifier|const
name|char
modifier|*
name|filename
decl_stmt|;
comment|/**    * \brief The actual file that the \#include/\#import directive resolved to.    */
name|CXFile
name|file
decl_stmt|;
name|int
name|isImport
decl_stmt|;
name|int
name|isAngled
decl_stmt|;
comment|/**    * \brief Non-zero if the directive was automatically turned into a module    * import.    */
name|int
name|isModuleImport
decl_stmt|;
block|}
name|CXIdxIncludedFileInfo
typedef|;
comment|/**  * \brief Data for IndexerCallbacks#importedASTFile.  */
typedef|typedef
struct|struct
block|{
comment|/**    * \brief Top level AST file containing the imported PCH, module or submodule.    */
name|CXFile
name|file
decl_stmt|;
comment|/**    * \brief The imported module or NULL if the AST file is a PCH.    */
name|CXModule
name|module
decl_stmt|;
comment|/**    * \brief Location where the file is imported. Applicable only for modules.    */
name|CXIdxLoc
name|loc
decl_stmt|;
comment|/**    * \brief Non-zero if an inclusion directive was automatically turned into    * a module import. Applicable only for modules.    */
name|int
name|isImplicit
decl_stmt|;
block|}
name|CXIdxImportedASTFileInfo
typedef|;
typedef|typedef
enum|enum
block|{
name|CXIdxEntity_Unexposed
init|=
literal|0
block|,
name|CXIdxEntity_Typedef
init|=
literal|1
block|,
name|CXIdxEntity_Function
init|=
literal|2
block|,
name|CXIdxEntity_Variable
init|=
literal|3
block|,
name|CXIdxEntity_Field
init|=
literal|4
block|,
name|CXIdxEntity_EnumConstant
init|=
literal|5
block|,
name|CXIdxEntity_ObjCClass
init|=
literal|6
block|,
name|CXIdxEntity_ObjCProtocol
init|=
literal|7
block|,
name|CXIdxEntity_ObjCCategory
init|=
literal|8
block|,
name|CXIdxEntity_ObjCInstanceMethod
init|=
literal|9
block|,
name|CXIdxEntity_ObjCClassMethod
init|=
literal|10
block|,
name|CXIdxEntity_ObjCProperty
init|=
literal|11
block|,
name|CXIdxEntity_ObjCIvar
init|=
literal|12
block|,
name|CXIdxEntity_Enum
init|=
literal|13
block|,
name|CXIdxEntity_Struct
init|=
literal|14
block|,
name|CXIdxEntity_Union
init|=
literal|15
block|,
name|CXIdxEntity_CXXClass
init|=
literal|16
block|,
name|CXIdxEntity_CXXNamespace
init|=
literal|17
block|,
name|CXIdxEntity_CXXNamespaceAlias
init|=
literal|18
block|,
name|CXIdxEntity_CXXStaticVariable
init|=
literal|19
block|,
name|CXIdxEntity_CXXStaticMethod
init|=
literal|20
block|,
name|CXIdxEntity_CXXInstanceMethod
init|=
literal|21
block|,
name|CXIdxEntity_CXXConstructor
init|=
literal|22
block|,
name|CXIdxEntity_CXXDestructor
init|=
literal|23
block|,
name|CXIdxEntity_CXXConversionFunction
init|=
literal|24
block|,
name|CXIdxEntity_CXXTypeAlias
init|=
literal|25
block|,
name|CXIdxEntity_CXXInterface
init|=
literal|26
block|}
name|CXIdxEntityKind
typedef|;
typedef|typedef
enum|enum
block|{
name|CXIdxEntityLang_None
init|=
literal|0
block|,
name|CXIdxEntityLang_C
init|=
literal|1
block|,
name|CXIdxEntityLang_ObjC
init|=
literal|2
block|,
name|CXIdxEntityLang_CXX
init|=
literal|3
block|,
name|CXIdxEntityLang_Swift
init|=
literal|4
block|}
name|CXIdxEntityLanguage
typedef|;
comment|/**  * \brief Extra C++ template information for an entity. This can apply to:  * CXIdxEntity_Function  * CXIdxEntity_CXXClass  * CXIdxEntity_CXXStaticMethod  * CXIdxEntity_CXXInstanceMethod  * CXIdxEntity_CXXConstructor  * CXIdxEntity_CXXConversionFunction  * CXIdxEntity_CXXTypeAlias  */
typedef|typedef
enum|enum
block|{
name|CXIdxEntity_NonTemplate
init|=
literal|0
block|,
name|CXIdxEntity_Template
init|=
literal|1
block|,
name|CXIdxEntity_TemplatePartialSpecialization
init|=
literal|2
block|,
name|CXIdxEntity_TemplateSpecialization
init|=
literal|3
block|}
name|CXIdxEntityCXXTemplateKind
typedef|;
typedef|typedef
enum|enum
block|{
name|CXIdxAttr_Unexposed
init|=
literal|0
block|,
name|CXIdxAttr_IBAction
init|=
literal|1
block|,
name|CXIdxAttr_IBOutlet
init|=
literal|2
block|,
name|CXIdxAttr_IBOutletCollection
init|=
literal|3
block|}
name|CXIdxAttrKind
typedef|;
typedef|typedef
struct|struct
block|{
name|CXIdxAttrKind
name|kind
decl_stmt|;
name|CXCursor
name|cursor
decl_stmt|;
name|CXIdxLoc
name|loc
decl_stmt|;
block|}
name|CXIdxAttrInfo
typedef|;
typedef|typedef
struct|struct
block|{
name|CXIdxEntityKind
name|kind
decl_stmt|;
name|CXIdxEntityCXXTemplateKind
name|templateKind
decl_stmt|;
name|CXIdxEntityLanguage
name|lang
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
specifier|const
name|char
modifier|*
name|USR
decl_stmt|;
name|CXCursor
name|cursor
decl_stmt|;
specifier|const
name|CXIdxAttrInfo
modifier|*
specifier|const
modifier|*
name|attributes
decl_stmt|;
name|unsigned
name|numAttributes
decl_stmt|;
block|}
name|CXIdxEntityInfo
typedef|;
typedef|typedef
struct|struct
block|{
name|CXCursor
name|cursor
decl_stmt|;
block|}
name|CXIdxContainerInfo
typedef|;
typedef|typedef
struct|struct
block|{
specifier|const
name|CXIdxAttrInfo
modifier|*
name|attrInfo
decl_stmt|;
specifier|const
name|CXIdxEntityInfo
modifier|*
name|objcClass
decl_stmt|;
name|CXCursor
name|classCursor
decl_stmt|;
name|CXIdxLoc
name|classLoc
decl_stmt|;
block|}
name|CXIdxIBOutletCollectionAttrInfo
typedef|;
typedef|typedef
enum|enum
block|{
name|CXIdxDeclFlag_Skipped
init|=
literal|0x1
block|}
name|CXIdxDeclInfoFlags
typedef|;
typedef|typedef
struct|struct
block|{
specifier|const
name|CXIdxEntityInfo
modifier|*
name|entityInfo
decl_stmt|;
name|CXCursor
name|cursor
decl_stmt|;
name|CXIdxLoc
name|loc
decl_stmt|;
specifier|const
name|CXIdxContainerInfo
modifier|*
name|semanticContainer
decl_stmt|;
comment|/**    * \brief Generally same as #semanticContainer but can be different in    * cases like out-of-line C++ member functions.    */
specifier|const
name|CXIdxContainerInfo
modifier|*
name|lexicalContainer
decl_stmt|;
name|int
name|isRedeclaration
decl_stmt|;
name|int
name|isDefinition
decl_stmt|;
name|int
name|isContainer
decl_stmt|;
specifier|const
name|CXIdxContainerInfo
modifier|*
name|declAsContainer
decl_stmt|;
comment|/**    * \brief Whether the declaration exists in code or was created implicitly    * by the compiler, e.g. implicit Objective-C methods for properties.    */
name|int
name|isImplicit
decl_stmt|;
specifier|const
name|CXIdxAttrInfo
modifier|*
specifier|const
modifier|*
name|attributes
decl_stmt|;
name|unsigned
name|numAttributes
decl_stmt|;
name|unsigned
name|flags
decl_stmt|;
block|}
name|CXIdxDeclInfo
typedef|;
typedef|typedef
enum|enum
block|{
name|CXIdxObjCContainer_ForwardRef
init|=
literal|0
block|,
name|CXIdxObjCContainer_Interface
init|=
literal|1
block|,
name|CXIdxObjCContainer_Implementation
init|=
literal|2
block|}
name|CXIdxObjCContainerKind
typedef|;
typedef|typedef
struct|struct
block|{
specifier|const
name|CXIdxDeclInfo
modifier|*
name|declInfo
decl_stmt|;
name|CXIdxObjCContainerKind
name|kind
decl_stmt|;
block|}
name|CXIdxObjCContainerDeclInfo
typedef|;
typedef|typedef
struct|struct
block|{
specifier|const
name|CXIdxEntityInfo
modifier|*
name|base
decl_stmt|;
name|CXCursor
name|cursor
decl_stmt|;
name|CXIdxLoc
name|loc
decl_stmt|;
block|}
name|CXIdxBaseClassInfo
typedef|;
typedef|typedef
struct|struct
block|{
specifier|const
name|CXIdxEntityInfo
modifier|*
name|protocol
decl_stmt|;
name|CXCursor
name|cursor
decl_stmt|;
name|CXIdxLoc
name|loc
decl_stmt|;
block|}
name|CXIdxObjCProtocolRefInfo
typedef|;
typedef|typedef
struct|struct
block|{
specifier|const
name|CXIdxObjCProtocolRefInfo
modifier|*
specifier|const
modifier|*
name|protocols
decl_stmt|;
name|unsigned
name|numProtocols
decl_stmt|;
block|}
name|CXIdxObjCProtocolRefListInfo
typedef|;
typedef|typedef
struct|struct
block|{
specifier|const
name|CXIdxObjCContainerDeclInfo
modifier|*
name|containerInfo
decl_stmt|;
specifier|const
name|CXIdxBaseClassInfo
modifier|*
name|superInfo
decl_stmt|;
specifier|const
name|CXIdxObjCProtocolRefListInfo
modifier|*
name|protocols
decl_stmt|;
block|}
name|CXIdxObjCInterfaceDeclInfo
typedef|;
typedef|typedef
struct|struct
block|{
specifier|const
name|CXIdxObjCContainerDeclInfo
modifier|*
name|containerInfo
decl_stmt|;
specifier|const
name|CXIdxEntityInfo
modifier|*
name|objcClass
decl_stmt|;
name|CXCursor
name|classCursor
decl_stmt|;
name|CXIdxLoc
name|classLoc
decl_stmt|;
specifier|const
name|CXIdxObjCProtocolRefListInfo
modifier|*
name|protocols
decl_stmt|;
block|}
name|CXIdxObjCCategoryDeclInfo
typedef|;
typedef|typedef
struct|struct
block|{
specifier|const
name|CXIdxDeclInfo
modifier|*
name|declInfo
decl_stmt|;
specifier|const
name|CXIdxEntityInfo
modifier|*
name|getter
decl_stmt|;
specifier|const
name|CXIdxEntityInfo
modifier|*
name|setter
decl_stmt|;
block|}
name|CXIdxObjCPropertyDeclInfo
typedef|;
typedef|typedef
struct|struct
block|{
specifier|const
name|CXIdxDeclInfo
modifier|*
name|declInfo
decl_stmt|;
specifier|const
name|CXIdxBaseClassInfo
modifier|*
specifier|const
modifier|*
name|bases
decl_stmt|;
name|unsigned
name|numBases
decl_stmt|;
block|}
name|CXIdxCXXClassDeclInfo
typedef|;
comment|/**  * \brief Data for IndexerCallbacks#indexEntityReference.  */
typedef|typedef
enum|enum
block|{
comment|/**    * \brief The entity is referenced directly in user's code.    */
name|CXIdxEntityRef_Direct
init|=
literal|1
block|,
comment|/**    * \brief An implicit reference, e.g. a reference of an Objective-C method    * via the dot syntax.    */
name|CXIdxEntityRef_Implicit
init|=
literal|2
block|}
name|CXIdxEntityRefKind
typedef|;
comment|/**  * \brief Data for IndexerCallbacks#indexEntityReference.  */
typedef|typedef
struct|struct
block|{
name|CXIdxEntityRefKind
name|kind
decl_stmt|;
comment|/**    * \brief Reference cursor.    */
name|CXCursor
name|cursor
decl_stmt|;
name|CXIdxLoc
name|loc
decl_stmt|;
comment|/**    * \brief The entity that gets referenced.    */
specifier|const
name|CXIdxEntityInfo
modifier|*
name|referencedEntity
decl_stmt|;
comment|/**    * \brief Immediate "parent" of the reference. For example:    *     * \code    * Foo *var;    * \endcode    *     * The parent of reference of type 'Foo' is the variable 'var'.    * For references inside statement bodies of functions/methods,    * the parentEntity will be the function/method.    */
specifier|const
name|CXIdxEntityInfo
modifier|*
name|parentEntity
decl_stmt|;
comment|/**    * \brief Lexical container context of the reference.    */
specifier|const
name|CXIdxContainerInfo
modifier|*
name|container
decl_stmt|;
block|}
name|CXIdxEntityRefInfo
typedef|;
comment|/**  * \brief A group of callbacks used by #clang_indexSourceFile and  * #clang_indexTranslationUnit.  */
typedef|typedef
struct|struct
block|{
comment|/**    * \brief Called periodically to check whether indexing should be aborted.    * Should return 0 to continue, and non-zero to abort.    */
name|int
function_decl|(
modifier|*
name|abortQuery
function_decl|)
parameter_list|(
name|CXClientData
name|client_data
parameter_list|,
name|void
modifier|*
name|reserved
parameter_list|)
function_decl|;
comment|/**    * \brief Called at the end of indexing; passes the complete diagnostic set.    */
name|void
function_decl|(
modifier|*
name|diagnostic
function_decl|)
parameter_list|(
name|CXClientData
name|client_data
parameter_list|,
name|CXDiagnosticSet
parameter_list|,
name|void
modifier|*
name|reserved
parameter_list|)
function_decl|;
name|CXIdxClientFile
function_decl|(
modifier|*
name|enteredMainFile
function_decl|)
parameter_list|(
name|CXClientData
name|client_data
parameter_list|,
name|CXFile
name|mainFile
parameter_list|,
name|void
modifier|*
name|reserved
parameter_list|)
function_decl|;
comment|/**    * \brief Called when a file gets \#included/\#imported.    */
name|CXIdxClientFile
function_decl|(
modifier|*
name|ppIncludedFile
function_decl|)
parameter_list|(
name|CXClientData
name|client_data
parameter_list|,
specifier|const
name|CXIdxIncludedFileInfo
modifier|*
parameter_list|)
function_decl|;
comment|/**    * \brief Called when a AST file (PCH or module) gets imported.    *     * AST files will not get indexed (there will not be callbacks to index all    * the entities in an AST file). The recommended action is that, if the AST    * file is not already indexed, to initiate a new indexing job specific to    * the AST file.    */
name|CXIdxClientASTFile
function_decl|(
modifier|*
name|importedASTFile
function_decl|)
parameter_list|(
name|CXClientData
name|client_data
parameter_list|,
specifier|const
name|CXIdxImportedASTFileInfo
modifier|*
parameter_list|)
function_decl|;
comment|/**    * \brief Called at the beginning of indexing a translation unit.    */
name|CXIdxClientContainer
function_decl|(
modifier|*
name|startedTranslationUnit
function_decl|)
parameter_list|(
name|CXClientData
name|client_data
parameter_list|,
name|void
modifier|*
name|reserved
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|indexDeclaration
function_decl|)
parameter_list|(
name|CXClientData
name|client_data
parameter_list|,
specifier|const
name|CXIdxDeclInfo
modifier|*
parameter_list|)
function_decl|;
comment|/**    * \brief Called to index a reference of an entity.    */
name|void
function_decl|(
modifier|*
name|indexEntityReference
function_decl|)
parameter_list|(
name|CXClientData
name|client_data
parameter_list|,
specifier|const
name|CXIdxEntityRefInfo
modifier|*
parameter_list|)
function_decl|;
block|}
name|IndexerCallbacks
typedef|;
name|CINDEX_LINKAGE
name|int
name|clang_index_isEntityObjCContainerKind
parameter_list|(
name|CXIdxEntityKind
parameter_list|)
function_decl|;
name|CINDEX_LINKAGE
specifier|const
name|CXIdxObjCContainerDeclInfo
modifier|*
name|clang_index_getObjCContainerDeclInfo
parameter_list|(
specifier|const
name|CXIdxDeclInfo
modifier|*
parameter_list|)
function_decl|;
name|CINDEX_LINKAGE
specifier|const
name|CXIdxObjCInterfaceDeclInfo
modifier|*
name|clang_index_getObjCInterfaceDeclInfo
parameter_list|(
specifier|const
name|CXIdxDeclInfo
modifier|*
parameter_list|)
function_decl|;
name|CINDEX_LINKAGE
specifier|const
name|CXIdxObjCCategoryDeclInfo
modifier|*
name|clang_index_getObjCCategoryDeclInfo
parameter_list|(
specifier|const
name|CXIdxDeclInfo
modifier|*
parameter_list|)
function_decl|;
name|CINDEX_LINKAGE
specifier|const
name|CXIdxObjCProtocolRefListInfo
modifier|*
name|clang_index_getObjCProtocolRefListInfo
parameter_list|(
specifier|const
name|CXIdxDeclInfo
modifier|*
parameter_list|)
function_decl|;
name|CINDEX_LINKAGE
specifier|const
name|CXIdxObjCPropertyDeclInfo
modifier|*
name|clang_index_getObjCPropertyDeclInfo
parameter_list|(
specifier|const
name|CXIdxDeclInfo
modifier|*
parameter_list|)
function_decl|;
name|CINDEX_LINKAGE
specifier|const
name|CXIdxIBOutletCollectionAttrInfo
modifier|*
name|clang_index_getIBOutletCollectionAttrInfo
parameter_list|(
specifier|const
name|CXIdxAttrInfo
modifier|*
parameter_list|)
function_decl|;
name|CINDEX_LINKAGE
specifier|const
name|CXIdxCXXClassDeclInfo
modifier|*
name|clang_index_getCXXClassDeclInfo
parameter_list|(
specifier|const
name|CXIdxDeclInfo
modifier|*
parameter_list|)
function_decl|;
comment|/**  * \brief For retrieving a custom CXIdxClientContainer attached to a  * container.  */
name|CINDEX_LINKAGE
name|CXIdxClientContainer
name|clang_index_getClientContainer
parameter_list|(
specifier|const
name|CXIdxContainerInfo
modifier|*
parameter_list|)
function_decl|;
comment|/**  * \brief For setting a custom CXIdxClientContainer attached to a  * container.  */
name|CINDEX_LINKAGE
name|void
name|clang_index_setClientContainer
parameter_list|(
specifier|const
name|CXIdxContainerInfo
modifier|*
parameter_list|,
name|CXIdxClientContainer
parameter_list|)
function_decl|;
comment|/**  * \brief For retrieving a custom CXIdxClientEntity attached to an entity.  */
name|CINDEX_LINKAGE
name|CXIdxClientEntity
name|clang_index_getClientEntity
parameter_list|(
specifier|const
name|CXIdxEntityInfo
modifier|*
parameter_list|)
function_decl|;
comment|/**  * \brief For setting a custom CXIdxClientEntity attached to an entity.  */
name|CINDEX_LINKAGE
name|void
name|clang_index_setClientEntity
parameter_list|(
specifier|const
name|CXIdxEntityInfo
modifier|*
parameter_list|,
name|CXIdxClientEntity
parameter_list|)
function_decl|;
comment|/**  * \brief An indexing action/session, to be applied to one or multiple  * translation units.  */
typedef|typedef
name|void
modifier|*
name|CXIndexAction
typedef|;
comment|/**  * \brief An indexing action/session, to be applied to one or multiple  * translation units.  *  * \param CIdx The index object with which the index action will be associated.  */
name|CINDEX_LINKAGE
name|CXIndexAction
name|clang_IndexAction_create
parameter_list|(
name|CXIndex
name|CIdx
parameter_list|)
function_decl|;
comment|/**  * \brief Destroy the given index action.  *  * The index action must not be destroyed until all of the translation units  * created within that index action have been destroyed.  */
name|CINDEX_LINKAGE
name|void
name|clang_IndexAction_dispose
parameter_list|(
name|CXIndexAction
parameter_list|)
function_decl|;
typedef|typedef
enum|enum
block|{
comment|/**    * \brief Used to indicate that no special indexing options are needed.    */
name|CXIndexOpt_None
init|=
literal|0x0
block|,
comment|/**    * \brief Used to indicate that IndexerCallbacks#indexEntityReference should    * be invoked for only one reference of an entity per source file that does    * not also include a declaration/definition of the entity.    */
name|CXIndexOpt_SuppressRedundantRefs
init|=
literal|0x1
block|,
comment|/**    * \brief Function-local symbols should be indexed. If this is not set    * function-local symbols will be ignored.    */
name|CXIndexOpt_IndexFunctionLocalSymbols
init|=
literal|0x2
block|,
comment|/**    * \brief Implicit function/class template instantiations should be indexed.    * If this is not set, implicit instantiations will be ignored.    */
name|CXIndexOpt_IndexImplicitTemplateInstantiations
init|=
literal|0x4
block|,
comment|/**    * \brief Suppress all compiler warnings when parsing for indexing.    */
name|CXIndexOpt_SuppressWarnings
init|=
literal|0x8
block|,
comment|/**    * \brief Skip a function/method body that was already parsed during an    * indexing session associated with a \c CXIndexAction object.    * Bodies in system headers are always skipped.    */
name|CXIndexOpt_SkipParsedBodiesInSession
init|=
literal|0x10
block|}
name|CXIndexOptFlags
typedef|;
comment|/**  * \brief Index the given source file and the translation unit corresponding  * to that file via callbacks implemented through #IndexerCallbacks.  *  * \param client_data pointer data supplied by the client, which will  * be passed to the invoked callbacks.  *  * \param index_callbacks Pointer to indexing callbacks that the client  * implements.  *  * \param index_callbacks_size Size of #IndexerCallbacks structure that gets  * passed in index_callbacks.  *  * \param index_options A bitmask of options that affects how indexing is  * performed. This should be a bitwise OR of the CXIndexOpt_XXX flags.  *  * \param[out] out_TU pointer to store a \c CXTranslationUnit that can be  * reused after indexing is finished. Set to \c NULL if you do not require it.  *  * \returns 0 on success or if there were errors from which the compiler could  * recover.  If there is a failure from which there is no recovery, returns  * a non-zero \c CXErrorCode.  *  * The rest of the parameters are the same as #clang_parseTranslationUnit.  */
name|CINDEX_LINKAGE
name|int
name|clang_indexSourceFile
parameter_list|(
name|CXIndexAction
parameter_list|,
name|CXClientData
name|client_data
parameter_list|,
name|IndexerCallbacks
modifier|*
name|index_callbacks
parameter_list|,
name|unsigned
name|index_callbacks_size
parameter_list|,
name|unsigned
name|index_options
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
name|CXTranslationUnit
modifier|*
name|out_TU
parameter_list|,
name|unsigned
name|TU_options
parameter_list|)
function_decl|;
comment|/**  * \brief Same as clang_indexSourceFile but requires a full command line  * for \c command_line_args including argv[0]. This is useful if the standard  * library paths are relative to the binary.  */
name|CINDEX_LINKAGE
name|int
name|clang_indexSourceFileFullArgv
parameter_list|(
name|CXIndexAction
parameter_list|,
name|CXClientData
name|client_data
parameter_list|,
name|IndexerCallbacks
modifier|*
name|index_callbacks
parameter_list|,
name|unsigned
name|index_callbacks_size
parameter_list|,
name|unsigned
name|index_options
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
name|CXTranslationUnit
modifier|*
name|out_TU
parameter_list|,
name|unsigned
name|TU_options
parameter_list|)
function_decl|;
comment|/**  * \brief Index the given translation unit via callbacks implemented through  * #IndexerCallbacks.  *   * The order of callback invocations is not guaranteed to be the same as  * when indexing a source file. The high level order will be:  *   *   -Preprocessor callbacks invocations  *   -Declaration/reference callbacks invocations  *   -Diagnostic callback invocations  *  * The parameters are the same as #clang_indexSourceFile.  *   * \returns If there is a failure from which there is no recovery, returns  * non-zero, otherwise returns 0.  */
name|CINDEX_LINKAGE
name|int
name|clang_indexTranslationUnit
parameter_list|(
name|CXIndexAction
parameter_list|,
name|CXClientData
name|client_data
parameter_list|,
name|IndexerCallbacks
modifier|*
name|index_callbacks
parameter_list|,
name|unsigned
name|index_callbacks_size
parameter_list|,
name|unsigned
name|index_options
parameter_list|,
name|CXTranslationUnit
parameter_list|)
function_decl|;
comment|/**  * \brief Retrieve the CXIdxFile, file, line, column, and offset represented by  * the given CXIdxLoc.  *  * If the location refers into a macro expansion, retrieves the  * location of the macro expansion and if it refers into a macro argument  * retrieves the location of the argument.  */
name|CINDEX_LINKAGE
name|void
name|clang_indexLoc_getFileLocation
parameter_list|(
name|CXIdxLoc
name|loc
parameter_list|,
name|CXIdxClientFile
modifier|*
name|indexFile
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
comment|/**  * \brief Retrieve the CXSourceLocation represented by the given CXIdxLoc.  */
name|CINDEX_LINKAGE
name|CXSourceLocation
name|clang_indexLoc_getCXSourceLocation
parameter_list|(
name|CXIdxLoc
name|loc
parameter_list|)
function_decl|;
comment|/**  * \brief Visitor invoked for each field found by a traversal.  *  * This visitor function will be invoked for each field found by  * \c clang_Type_visitFields. Its first argument is the cursor being  * visited, its second argument is the client data provided to  * \c clang_Type_visitFields.  *  * The visitor should return one of the \c CXVisitorResult values  * to direct \c clang_Type_visitFields.  */
typedef|typedef
name|enum
name|CXVisitorResult
function_decl|(
modifier|*
name|CXFieldVisitor
function_decl|)
parameter_list|(
name|CXCursor
name|C
parameter_list|,
name|CXClientData
name|client_data
parameter_list|)
function_decl|;
comment|/**  * \brief Visit the fields of a particular type.  *  * This function visits all the direct fields of the given cursor,  * invoking the given \p visitor function with the cursors of each  * visited field. The traversal may be ended prematurely, if  * the visitor returns \c CXFieldVisit_Break.  *  * \param T the record type whose field may be visited.  *  * \param visitor the visitor function that will be invoked for each  * field of \p T.  *  * \param client_data pointer data supplied by the client, which will  * be passed to the visitor each time it is invoked.  *  * \returns a non-zero value if the traversal was terminated  * prematurely by the visitor returning \c CXFieldVisit_Break.  */
name|CINDEX_LINKAGE
name|unsigned
name|clang_Type_visitFields
parameter_list|(
name|CXType
name|T
parameter_list|,
name|CXFieldVisitor
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

