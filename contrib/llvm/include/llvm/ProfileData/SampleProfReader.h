begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SampleProfReader.h - Read LLVM sample profile data -------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                      The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file contains definitions needed for reading sample profiles.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// NOTE: If you are making changes to this file format, please remember
end_comment

begin_comment
comment|//       to document them in the Clang documentation at
end_comment

begin_comment
comment|//       tools/clang/docs/UsersManual.rst.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Text format
end_comment

begin_comment
comment|// -----------
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Sample profiles are written as ASCII text. The file is divided into
end_comment

begin_comment
comment|// sections, which correspond to each of the functions executed at runtime.
end_comment

begin_comment
comment|// Each section has the following format
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//     function1:total_samples:total_head_samples
end_comment

begin_comment
comment|//      offset1[.discriminator]: number_of_samples [fn1:num fn2:num ... ]
end_comment

begin_comment
comment|//      offset2[.discriminator]: number_of_samples [fn3:num fn4:num ... ]
end_comment

begin_comment
comment|//      ...
end_comment

begin_comment
comment|//      offsetN[.discriminator]: number_of_samples [fn5:num fn6:num ... ]
end_comment

begin_comment
comment|//      offsetA[.discriminator]: fnA:num_of_total_samples
end_comment

begin_comment
comment|//       offsetA1[.discriminator]: number_of_samples [fn7:num fn8:num ... ]
end_comment

begin_comment
comment|//       ...
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This is a nested tree in which the identation represents the nesting level
end_comment

begin_comment
comment|// of the inline stack. There are no blank lines in the file. And the spacing
end_comment

begin_comment
comment|// within a single line is fixed. Additional spaces will result in an error
end_comment

begin_comment
comment|// while reading the file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Any line starting with the '#' character is completely ignored.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Inlined calls are represented with indentation. The Inline stack is a
end_comment

begin_comment
comment|// stack of source locations in which the top of the stack represents the
end_comment

begin_comment
comment|// leaf function, and the bottom of the stack represents the actual
end_comment

begin_comment
comment|// symbol to which the instruction belongs.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Function names must be mangled in order for the profile loader to
end_comment

begin_comment
comment|// match them in the current translation unit. The two numbers in the
end_comment

begin_comment
comment|// function header specify how many total samples were accumulated in the
end_comment

begin_comment
comment|// function (first number), and the total number of samples accumulated
end_comment

begin_comment
comment|// in the prologue of the function (second number). This head sample
end_comment

begin_comment
comment|// count provides an indicator of how frequently the function is invoked.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// There are two types of lines in the function body.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// * Sampled line represents the profile information of a source location.
end_comment

begin_comment
comment|// * Callsite line represents the profile information of a callsite.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Each sampled line may contain several items. Some are optional (marked
end_comment

begin_comment
comment|// below):
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// a. Source line offset. This number represents the line number
end_comment

begin_comment
comment|//    in the function where the sample was collected. The line number is
end_comment

begin_comment
comment|//    always relative to the line where symbol of the function is
end_comment

begin_comment
comment|//    defined. So, if the function has its header at line 280, the offset
end_comment

begin_comment
comment|//    13 is at line 293 in the file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    Note that this offset should never be a negative number. This could
end_comment

begin_comment
comment|//    happen in cases like macros. The debug machinery will register the
end_comment

begin_comment
comment|//    line number at the point of macro expansion. So, if the macro was
end_comment

begin_comment
comment|//    expanded in a line before the start of the function, the profile
end_comment

begin_comment
comment|//    converter should emit a 0 as the offset (this means that the optimizers
end_comment

begin_comment
comment|//    will not be able to associate a meaningful weight to the instructions
end_comment

begin_comment
comment|//    in the macro).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// b. [OPTIONAL] Discriminator. This is used if the sampled program
end_comment

begin_comment
comment|//    was compiled with DWARF discriminator support
end_comment

begin_comment
comment|//    (http://wiki.dwarfstd.org/index.php?title=Path_Discriminators).
end_comment

begin_comment
comment|//    DWARF discriminators are unsigned integer values that allow the
end_comment

begin_comment
comment|//    compiler to distinguish between multiple execution paths on the
end_comment

begin_comment
comment|//    same source line location.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    For example, consider the line of code ``if (cond) foo(); else bar();``.
end_comment

begin_comment
comment|//    If the predicate ``cond`` is true 80% of the time, then the edge
end_comment

begin_comment
comment|//    into function ``foo`` should be considered to be taken most of the
end_comment

begin_comment
comment|//    time. But both calls to ``foo`` and ``bar`` are at the same source
end_comment

begin_comment
comment|//    line, so a sample count at that line is not sufficient. The
end_comment

begin_comment
comment|//    compiler needs to know which part of that line is taken more
end_comment

begin_comment
comment|//    frequently.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    This is what discriminators provide. In this case, the calls to
end_comment

begin_comment
comment|//    ``foo`` and ``bar`` will be at the same line, but will have
end_comment

begin_comment
comment|//    different discriminator values. This allows the compiler to correctly
end_comment

begin_comment
comment|//    set edge weights into ``foo`` and ``bar``.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// c. Number of samples. This is an integer quantity representing the
end_comment

begin_comment
comment|//    number of samples collected by the profiler at this source
end_comment

begin_comment
comment|//    location.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// d. [OPTIONAL] Potential call targets and samples. If present, this
end_comment

begin_comment
comment|//    line contains a call instruction. This models both direct and
end_comment

begin_comment
comment|//    number of samples. For example,
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//      130: 7  foo:3  bar:2  baz:7
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//    The above means that at relative line offset 130 there is a call
end_comment

begin_comment
comment|//    instruction that calls one of ``foo()``, ``bar()`` and ``baz()``,
end_comment

begin_comment
comment|//    with ``baz()`` being the relatively more frequently called target.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Each callsite line may contain several items. Some are optional.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// a. Source line offset. This number represents the line number of the
end_comment

begin_comment
comment|//    callsite that is inlined in the profiled binary.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// b. [OPTIONAL] Discriminator. Same as the discriminator for sampled line.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// c. Number of samples. This is an integer quantity representing the
end_comment

begin_comment
comment|//    total number of samples collected for the inlined instance at this
end_comment

begin_comment
comment|//    callsite
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Binary format
end_comment

begin_comment
comment|// -------------
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This is a more compact encoding. Numbers are encoded as ULEB128 values
end_comment

begin_comment
comment|// and all strings are encoded in a name table. The file is organized in
end_comment

begin_comment
comment|// the following sections:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MAGIC (uint64_t)
end_comment

begin_comment
comment|//    File identifier computed by function SPMagic() (0x5350524f463432ff)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// VERSION (uint32_t)
end_comment

begin_comment
comment|//    File format version number computed by SPVersion()
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// SUMMARY
end_comment

begin_comment
comment|//    TOTAL_COUNT (uint64_t)
end_comment

begin_comment
comment|//        Total number of samples in the profile.
end_comment

begin_comment
comment|//    MAX_COUNT (uint64_t)
end_comment

begin_comment
comment|//        Maximum value of samples on a line.
end_comment

begin_comment
comment|//    MAX_FUNCTION_COUNT (uint64_t)
end_comment

begin_comment
comment|//        Maximum number of samples at function entry (head samples).
end_comment

begin_comment
comment|//    NUM_COUNTS (uint64_t)
end_comment

begin_comment
comment|//        Number of lines with samples.
end_comment

begin_comment
comment|//    NUM_FUNCTIONS (uint64_t)
end_comment

begin_comment
comment|//        Number of functions with samples.
end_comment

begin_comment
comment|//    NUM_DETAILED_SUMMARY_ENTRIES (size_t)
end_comment

begin_comment
comment|//        Number of entries in detailed summary
end_comment

begin_comment
comment|//    DETAILED_SUMMARY
end_comment

begin_comment
comment|//        A list of detailed summary entry. Each entry consists of
end_comment

begin_comment
comment|//        CUTOFF (uint32_t)
end_comment

begin_comment
comment|//            Required percentile of total sample count expressed as a fraction
end_comment

begin_comment
comment|//            multiplied by 1000000.
end_comment

begin_comment
comment|//        MIN_COUNT (uint64_t)
end_comment

begin_comment
comment|//            The minimum number of samples required to reach the target
end_comment

begin_comment
comment|//            CUTOFF.
end_comment

begin_comment
comment|//        NUM_COUNTS (uint64_t)
end_comment

begin_comment
comment|//            Number of samples to get to the desrired percentile.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// NAME TABLE
end_comment

begin_comment
comment|//    SIZE (uint32_t)
end_comment

begin_comment
comment|//        Number of entries in the name table.
end_comment

begin_comment
comment|//    NAMES
end_comment

begin_comment
comment|//        A NUL-separated list of SIZE strings.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// FUNCTION BODY (one for each uninlined function body present in the profile)
end_comment

begin_comment
comment|//    HEAD_SAMPLES (uint64_t) [only for top-level functions]
end_comment

begin_comment
comment|//        Total number of samples collected at the head (prologue) of the
end_comment

begin_comment
comment|//        function.
end_comment

begin_comment
comment|//        NOTE: This field should only be present for top-level functions
end_comment

begin_comment
comment|//              (i.e., not inlined into any caller). Inlined function calls
end_comment

begin_comment
comment|//              have no prologue, so they don't need this.
end_comment

begin_comment
comment|//    NAME_IDX (uint32_t)
end_comment

begin_comment
comment|//        Index into the name table indicating the function name.
end_comment

begin_comment
comment|//    SAMPLES (uint64_t)
end_comment

begin_comment
comment|//        Total number of samples collected in this function.
end_comment

begin_comment
comment|//    NRECS (uint32_t)
end_comment

begin_comment
comment|//        Total number of sampling records this function's profile.
end_comment

begin_comment
comment|//    BODY RECORDS
end_comment

begin_comment
comment|//        A list of NRECS entries. Each entry contains:
end_comment

begin_comment
comment|//          OFFSET (uint32_t)
end_comment

begin_comment
comment|//            Line offset from the start of the function.
end_comment

begin_comment
comment|//          DISCRIMINATOR (uint32_t)
end_comment

begin_comment
comment|//            Discriminator value (see description of discriminators
end_comment

begin_comment
comment|//            in the text format documentation above).
end_comment

begin_comment
comment|//          SAMPLES (uint64_t)
end_comment

begin_comment
comment|//            Number of samples collected at this location.
end_comment

begin_comment
comment|//          NUM_CALLS (uint32_t)
end_comment

begin_comment
comment|//            Number of non-inlined function calls made at this location. In the
end_comment

begin_comment
comment|//            case of direct calls, this number will always be 1. For indirect
end_comment

begin_comment
comment|//            calls (virtual functions and function pointers) this will
end_comment

begin_comment
comment|//            represent all the actual functions called at runtime.
end_comment

begin_comment
comment|//          CALL_TARGETS
end_comment

begin_comment
comment|//            A list of NUM_CALLS entries for each called function:
end_comment

begin_comment
comment|//               NAME_IDX (uint32_t)
end_comment

begin_comment
comment|//                  Index into the name table with the callee name.
end_comment

begin_comment
comment|//               SAMPLES (uint64_t)
end_comment

begin_comment
comment|//                  Number of samples collected at the call site.
end_comment

begin_comment
comment|//    NUM_INLINED_FUNCTIONS (uint32_t)
end_comment

begin_comment
comment|//      Number of callees inlined into this function.
end_comment

begin_comment
comment|//    INLINED FUNCTION RECORDS
end_comment

begin_comment
comment|//      A list of NUM_INLINED_FUNCTIONS entries describing each of the inlined
end_comment

begin_comment
comment|//      callees.
end_comment

begin_comment
comment|//        OFFSET (uint32_t)
end_comment

begin_comment
comment|//          Line offset from the start of the function.
end_comment

begin_comment
comment|//        DISCRIMINATOR (uint32_t)
end_comment

begin_comment
comment|//          Discriminator value (see description of discriminators
end_comment

begin_comment
comment|//          in the text format documentation above).
end_comment

begin_comment
comment|//        FUNCTION BODY
end_comment

begin_comment
comment|//          A FUNCTION BODY entry describing the inlined function.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_PROFILEDATA_SAMPLEPROFREADER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_PROFILEDATA_SAMPLEPROFREADER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Twine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DiagnosticInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Function.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/LLVMContext.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ProfileSummary.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ProfileData/SampleProf.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Debug.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorOr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/GCOV.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MemoryBuffer.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<system_error>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
name|namespace
name|sampleprof
block|{
comment|/// \brief Sample-based profile reader.
comment|///
comment|/// Each profile contains sample counts for all the functions
comment|/// executed. Inside each function, statements are annotated with the
comment|/// collected samples on all the instructions associated with that
comment|/// statement.
comment|///
comment|/// For this to produce meaningful data, the program needs to be
comment|/// compiled with some debug information (at minimum, line numbers:
comment|/// -gline-tables-only). Otherwise, it will be impossible to match IR
comment|/// instructions to the line numbers collected by the profiler.
comment|///
comment|/// From the profile file, we are interested in collecting the
comment|/// following information:
comment|///
comment|/// * A list of functions included in the profile (mangled names).
comment|///
comment|/// * For each function F:
comment|///   1. The total number of samples collected in F.
comment|///
comment|///   2. The samples collected at each line in F. To provide some
comment|///      protection against source code shuffling, line numbers should
comment|///      be relative to the start of the function.
comment|///
comment|/// The reader supports two file formats: text and binary. The text format
comment|/// is useful for debugging and testing, while the binary format is more
comment|/// compact and I/O efficient. They can both be used interchangeably.
name|class
name|SampleProfileReader
block|{
name|public
label|:
name|SampleProfileReader
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|B
argument_list|,
name|LLVMContext
operator|&
name|C
argument_list|)
operator|:
name|Profiles
argument_list|(
literal|0
argument_list|)
operator|,
name|Ctx
argument_list|(
name|C
argument_list|)
operator|,
name|Buffer
argument_list|(
argument|std::move(B)
argument_list|)
block|{}
name|virtual
operator|~
name|SampleProfileReader
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// \brief Read and validate the file header.
name|virtual
name|std
operator|::
name|error_code
name|readHeader
argument_list|()
operator|=
literal|0
expr_stmt|;
comment|/// \brief Read sample profiles from the associated file.
name|virtual
name|std
operator|::
name|error_code
name|read
argument_list|()
operator|=
literal|0
expr_stmt|;
comment|/// \brief Print the profile for \p FName on stream \p OS.
name|void
name|dumpFunctionProfile
parameter_list|(
name|StringRef
name|FName
parameter_list|,
name|raw_ostream
modifier|&
name|OS
init|=
name|dbgs
argument_list|()
parameter_list|)
function_decl|;
comment|/// \brief Print all the profiles on stream \p OS.
name|void
name|dump
parameter_list|(
name|raw_ostream
modifier|&
name|OS
init|=
name|dbgs
argument_list|()
parameter_list|)
function_decl|;
comment|/// \brief Return the samples collected for function \p F.
name|FunctionSamples
modifier|*
name|getSamplesFor
parameter_list|(
specifier|const
name|Function
modifier|&
name|F
parameter_list|)
block|{
comment|// The function name may have been updated by adding suffix. In sample
comment|// profile, the function names are all stripped, so we need to strip
comment|// the function name suffix before matching with profile.
if|if
condition|(
name|Profiles
operator|.
name|count
argument_list|(
name|F
operator|.
name|getName
argument_list|()
operator|.
name|split
argument_list|(
literal|'.'
argument_list|)
operator|.
name|first
argument_list|)
condition|)
return|return
operator|&
name|Profiles
index|[
operator|(
name|F
operator|.
name|getName
argument_list|()
operator|.
name|split
argument_list|(
literal|'.'
argument_list|)
operator|.
name|first
operator|)
index|]
return|;
return|return
name|nullptr
return|;
block|}
comment|/// \brief Return all the profiles.
name|StringMap
operator|<
name|FunctionSamples
operator|>
operator|&
name|getProfiles
argument_list|()
block|{
return|return
name|Profiles
return|;
block|}
comment|/// \brief Report a parse error message.
name|void
name|reportError
argument_list|(
name|int64_t
name|LineNumber
argument_list|,
name|Twine
name|Msg
argument_list|)
decl|const
block|{
name|Ctx
operator|.
name|diagnose
argument_list|(
name|DiagnosticInfoSampleProfile
argument_list|(
name|Buffer
operator|->
name|getBufferIdentifier
argument_list|()
argument_list|,
name|LineNumber
argument_list|,
name|Msg
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Create a sample profile reader appropriate to the file format.
specifier|static
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|SampleProfileReader
operator|>>
name|create
argument_list|(
specifier|const
name|Twine
operator|&
name|Filename
argument_list|,
name|LLVMContext
operator|&
name|C
argument_list|)
expr_stmt|;
comment|/// \brief Create a sample profile reader from the supplied memory buffer.
specifier|static
name|ErrorOr
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|SampleProfileReader
operator|>>
name|create
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
operator|&
name|B
argument_list|,
name|LLVMContext
operator|&
name|C
argument_list|)
expr_stmt|;
comment|/// \brief Return the profile summary.
name|ProfileSummary
modifier|&
name|getSummary
parameter_list|()
block|{
return|return
operator|*
operator|(
name|Summary
operator|.
name|get
argument_list|()
operator|)
return|;
block|}
name|protected
label|:
comment|/// \brief Map every function to its associated profile.
comment|///
comment|/// The profile of every function executed at runtime is collected
comment|/// in the structure FunctionSamples. This maps function objects
comment|/// to their corresponding profiles.
name|StringMap
operator|<
name|FunctionSamples
operator|>
name|Profiles
expr_stmt|;
comment|/// \brief LLVM context used to emit diagnostics.
name|LLVMContext
modifier|&
name|Ctx
decl_stmt|;
comment|/// \brief Memory buffer holding the profile file.
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|Buffer
expr_stmt|;
comment|/// \brief Profile summary information.
name|std
operator|::
name|unique_ptr
operator|<
name|ProfileSummary
operator|>
name|Summary
expr_stmt|;
comment|/// \brief Compute summary for this profile.
name|void
name|computeSummary
parameter_list|()
function_decl|;
block|}
empty_stmt|;
name|class
name|SampleProfileReaderText
range|:
name|public
name|SampleProfileReader
block|{
name|public
operator|:
name|SampleProfileReaderText
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|B
argument_list|,
name|LLVMContext
operator|&
name|C
argument_list|)
operator|:
name|SampleProfileReader
argument_list|(
argument|std::move(B)
argument_list|,
argument|C
argument_list|)
block|{}
comment|/// \brief Read and validate the file header.
name|std
operator|::
name|error_code
name|readHeader
argument_list|()
name|override
block|{
return|return
name|sampleprof_error
operator|::
name|success
return|;
block|}
comment|/// \brief Read sample profiles from the associated file.
name|std
operator|::
name|error_code
name|read
argument_list|()
name|override
block|;
comment|/// \brief Return true if \p Buffer is in the format supported by this class.
specifier|static
name|bool
name|hasFormat
argument_list|(
specifier|const
name|MemoryBuffer
operator|&
name|Buffer
argument_list|)
block|; }
decl_stmt|;
name|class
name|SampleProfileReaderBinary
range|:
name|public
name|SampleProfileReader
block|{
name|public
operator|:
name|SampleProfileReaderBinary
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|B
argument_list|,
name|LLVMContext
operator|&
name|C
argument_list|)
operator|:
name|SampleProfileReader
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|B
argument_list|)
argument_list|,
name|C
argument_list|)
block|,
name|Data
argument_list|(
name|nullptr
argument_list|)
block|,
name|End
argument_list|(
argument|nullptr
argument_list|)
block|{}
comment|/// \brief Read and validate the file header.
name|std
operator|::
name|error_code
name|readHeader
argument_list|()
name|override
block|;
comment|/// \brief Read sample profiles from the associated file.
name|std
operator|::
name|error_code
name|read
argument_list|()
name|override
block|;
comment|/// \brief Return true if \p Buffer is in the format supported by this class.
specifier|static
name|bool
name|hasFormat
argument_list|(
specifier|const
name|MemoryBuffer
operator|&
name|Buffer
argument_list|)
block|;
name|protected
operator|:
comment|/// \brief Read a numeric value of type T from the profile.
comment|///
comment|/// If an error occurs during decoding, a diagnostic message is emitted and
comment|/// EC is set.
comment|///
comment|/// \returns the read value.
name|template
operator|<
name|typename
name|T
operator|>
name|ErrorOr
operator|<
name|T
operator|>
name|readNumber
argument_list|()
block|;
comment|/// \brief Read a string from the profile.
comment|///
comment|/// If an error occurs during decoding, a diagnostic message is emitted and
comment|/// EC is set.
comment|///
comment|/// \returns the read value.
name|ErrorOr
operator|<
name|StringRef
operator|>
name|readString
argument_list|()
block|;
comment|/// Read a string indirectly via the name table.
name|ErrorOr
operator|<
name|StringRef
operator|>
name|readStringFromTable
argument_list|()
block|;
comment|/// \brief Return true if we've reached the end of file.
name|bool
name|at_eof
argument_list|()
specifier|const
block|{
return|return
name|Data
operator|>=
name|End
return|;
block|}
comment|/// Read the contents of the given profile instance.
name|std
operator|::
name|error_code
name|readProfile
argument_list|(
name|FunctionSamples
operator|&
name|FProfile
argument_list|)
block|;
comment|/// \brief Points to the current location in the buffer.
specifier|const
name|uint8_t
operator|*
name|Data
block|;
comment|/// \brief Points to the end of the buffer.
specifier|const
name|uint8_t
operator|*
name|End
block|;
comment|/// Function name table.
name|std
operator|::
name|vector
operator|<
name|StringRef
operator|>
name|NameTable
block|;
name|private
operator|:
name|std
operator|::
name|error_code
name|readSummaryEntry
argument_list|(
name|std
operator|::
name|vector
operator|<
name|ProfileSummaryEntry
operator|>
operator|&
name|Entries
argument_list|)
block|;
comment|/// \brief Read profile summary.
name|std
operator|::
name|error_code
name|readSummary
argument_list|()
block|; }
decl_stmt|;
typedef|typedef
name|SmallVector
operator|<
name|FunctionSamples
operator|*
operator|,
literal|10
operator|>
name|InlineCallStack
expr_stmt|;
comment|// Supported histogram types in GCC.  Currently, we only need support for
comment|// call target histograms.
enum|enum
name|HistType
block|{
name|HIST_TYPE_INTERVAL
block|,
name|HIST_TYPE_POW2
block|,
name|HIST_TYPE_SINGLE_VALUE
block|,
name|HIST_TYPE_CONST_DELTA
block|,
name|HIST_TYPE_INDIR_CALL
block|,
name|HIST_TYPE_AVERAGE
block|,
name|HIST_TYPE_IOR
block|,
name|HIST_TYPE_INDIR_CALL_TOPN
block|}
enum|;
name|class
name|SampleProfileReaderGCC
range|:
name|public
name|SampleProfileReader
block|{
name|public
operator|:
name|SampleProfileReaderGCC
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|B
argument_list|,
name|LLVMContext
operator|&
name|C
argument_list|)
operator|:
name|SampleProfileReader
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|B
argument_list|)
argument_list|,
name|C
argument_list|)
block|,
name|GcovBuffer
argument_list|(
argument|Buffer.get()
argument_list|)
block|{}
comment|/// \brief Read and validate the file header.
name|std
operator|::
name|error_code
name|readHeader
argument_list|()
name|override
block|;
comment|/// \brief Read sample profiles from the associated file.
name|std
operator|::
name|error_code
name|read
argument_list|()
name|override
block|;
comment|/// \brief Return true if \p Buffer is in the format supported by this class.
specifier|static
name|bool
name|hasFormat
argument_list|(
specifier|const
name|MemoryBuffer
operator|&
name|Buffer
argument_list|)
block|;
name|protected
operator|:
name|std
operator|::
name|error_code
name|readNameTable
argument_list|()
block|;
name|std
operator|::
name|error_code
name|readOneFunctionProfile
argument_list|(
argument|const InlineCallStack&InlineStack
argument_list|,
argument|bool Update
argument_list|,
argument|uint32_t Offset
argument_list|)
block|;
name|std
operator|::
name|error_code
name|readFunctionProfiles
argument_list|()
block|;
name|std
operator|::
name|error_code
name|skipNextWord
argument_list|()
block|;
name|template
operator|<
name|typename
name|T
operator|>
name|ErrorOr
operator|<
name|T
operator|>
name|readNumber
argument_list|()
block|;
name|ErrorOr
operator|<
name|StringRef
operator|>
name|readString
argument_list|()
block|;
comment|/// \brief Read the section tag and check that it's the same as \p Expected.
name|std
operator|::
name|error_code
name|readSectionTag
argument_list|(
argument|uint32_t Expected
argument_list|)
block|;
comment|/// GCOV buffer containing the profile.
name|GCOVBuffer
name|GcovBuffer
block|;
comment|/// Function names in this profile.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|Names
block|;
comment|/// GCOV tags used to separate sections in the profile file.
specifier|static
specifier|const
name|uint32_t
name|GCOVTagAFDOFileNames
operator|=
literal|0xaa000000
block|;
specifier|static
specifier|const
name|uint32_t
name|GCOVTagAFDOFunction
operator|=
literal|0xac000000
block|; }
decl_stmt|;
block|}
comment|// end namespace sampleprof
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_PROFILEDATA_SAMPLEPROFREADER_H
end_comment

end_unit

