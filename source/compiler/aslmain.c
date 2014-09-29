begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: aslmain - compiler main and utilities  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_define
define|#
directive|define
name|_DECLARE_GLOBALS
end_define

begin_include
include|#
directive|include
file|"aslcompiler.h"
end_include

begin_include
include|#
directive|include
file|"acapps.h"
end_include

begin_include
include|#
directive|include
file|"acdisasm.h"
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_define
define|#
directive|define
name|_COMPONENT
value|ACPI_COMPILER
end_define

begin_macro
name|ACPI_MODULE_NAME
argument_list|(
literal|"aslmain"
argument_list|)
end_macro

begin_comment
comment|/*  * Main routine for the iASL compiler.  *  * Portability note: The compiler depends upon the host for command-line  * wildcard support - it is not implemented locally. For example:  *  * Linux/Unix systems: Shell expands wildcards automatically.  *  * Windows: The setargv.obj module must be linked in to automatically  * expand wildcards.  */
end_comment

begin_comment
comment|/* Local prototypes */
end_comment

begin_function_decl
specifier|static
name|void
name|ACPI_SYSTEM_XFACE
name|AslSignalHandler
parameter_list|(
name|int
name|Sig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|AslInitialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT8
name|AcpiIsBigEndianMachine
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiIsBigEndianMachine  *  * PARAMETERS:  None  *  * RETURN:      TRUE if machine is big endian  *              FALSE if machine is little endian  *  * DESCRIPTION: Detect whether machine is little endian or big endian.  *  ******************************************************************************/
end_comment

begin_function
name|UINT8
name|AcpiIsBigEndianMachine
parameter_list|(
name|void
parameter_list|)
block|{
union|union
block|{
name|UINT32
name|Integer
decl_stmt|;
name|UINT8
name|Bytes
index|[
literal|4
index|]
decl_stmt|;
block|}
name|Overlay
init|=
block|{
literal|0xFF000000
block|}
union|;
return|return
operator|(
name|Overlay
operator|.
name|Bytes
index|[
literal|0
index|]
operator|)
return|;
comment|/* Returns 0xFF (TRUE) for big endian */
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    Usage  *  * PARAMETERS:  None  *  * RETURN:      None  *  * DESCRIPTION: Display option help message.  *              Optional items in square brackets.  *  ******************************************************************************/
end_comment

begin_function
name|void
name|Usage
parameter_list|(
name|void
parameter_list|)
block|{
name|printf
argument_list|(
literal|"%s\n\n"
argument_list|,
name|ASL_COMPLIANCE
argument_list|)
expr_stmt|;
name|ACPI_USAGE_HEADER
argument_list|(
literal|"iasl [Options] [Files]"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\nGeneral:\n"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-@<file>"
argument_list|,
literal|"Specify command file"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-I<dir>"
argument_list|,
literal|"Specify additional include directory"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-T<sig>|ALL|*"
argument_list|,
literal|"Create table template file for ACPI<Sig>"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-p<prefix>"
argument_list|,
literal|"Specify path/filename prefix for all output files"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-v"
argument_list|,
literal|"Display compiler version"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-vo"
argument_list|,
literal|"Enable optimization comments"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-vs"
argument_list|,
literal|"Disable signon"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\nHelp:\n"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-h"
argument_list|,
literal|"This message"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-hc"
argument_list|,
literal|"Display operators allowed in constant expressions"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-hf"
argument_list|,
literal|"Display help for output filename generation"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-hr"
argument_list|,
literal|"Display ACPI reserved method names"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-ht"
argument_list|,
literal|"Display currently supported ACPI table names"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\nPreprocessor:\n"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-D<symbol>"
argument_list|,
literal|"Define symbol for preprocessor use"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-li"
argument_list|,
literal|"Create preprocessed output file (*.i)"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-P"
argument_list|,
literal|"Preprocess only and create preprocessor output file (*.i)"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-Pn"
argument_list|,
literal|"Disable preprocessor"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\nErrors, Warnings, and Remarks:\n"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-va"
argument_list|,
literal|"Disable all errors/warnings/remarks"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-ve"
argument_list|,
literal|"Report only errors (ignore warnings and remarks)"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-vi"
argument_list|,
literal|"Less verbose errors and warnings for use with IDEs"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-vr"
argument_list|,
literal|"Disable remarks"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-vw<messageid>"
argument_list|,
literal|"Disable specific warning or remark"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-w1 -w2 -w3"
argument_list|,
literal|"Set warning reporting level"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-we"
argument_list|,
literal|"Report warnings as errors"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\nAML Code Generation (*.aml):\n"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-oa"
argument_list|,
literal|"Disable all optimizations (compatibility mode)"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-of"
argument_list|,
literal|"Disable constant folding"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-oi"
argument_list|,
literal|"Disable integer optimization to Zero/One/Ones"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-on"
argument_list|,
literal|"Disable named reference string optimization"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-cr"
argument_list|,
literal|"Disable Resource Descriptor error checking"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-in"
argument_list|,
literal|"Ignore NoOp operators"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-r<revision>"
argument_list|,
literal|"Override table header Revision (1-255)"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\nOptional Source Code Output Files:\n"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-sc -sa"
argument_list|,
literal|"Create source file in C or assembler (*.c or *.asm)"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-ic -ia"
argument_list|,
literal|"Create include file in C or assembler (*.h or *.inc)"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-tc -ta -ts"
argument_list|,
literal|"Create hex AML table in C, assembler, or ASL (*.hex)"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-so"
argument_list|,
literal|"Create offset table in C (*.offset.h)"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\nOptional Listing Files:\n"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-l"
argument_list|,
literal|"Create mixed listing file (ASL source and AML) (*.lst)"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-lm"
argument_list|,
literal|"Create hardware summary map file (*.map)"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-ln"
argument_list|,
literal|"Create namespace file (*.nsp)"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-ls"
argument_list|,
literal|"Create combined source file (expanded includes) (*.src)"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\nData Table Compiler:\n"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-G"
argument_list|,
literal|"Compile custom table that contains generic operators"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-vt"
argument_list|,
literal|"Create verbose template files (full disassembly)"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\nAML Disassembler:\n"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-d<f1 f2 ...>"
argument_list|,
literal|"Disassemble or decode binary ACPI tables to file (*.dsl)"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|""
argument_list|,
literal|"  (Optional, file type is automatically detected)"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-da<f1 f2 ...>"
argument_list|,
literal|"Disassemble multiple tables from single namespace"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-db"
argument_list|,
literal|"Do not translate Buffers to Resource Templates"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-dc<f1 f2 ...>"
argument_list|,
literal|"Disassemble AML and immediately compile it"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|""
argument_list|,
literal|"  (Obtain DSDT from current system if no input file)"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-e<f1 f2 ...>"
argument_list|,
literal|"Include ACPI table(s) for external symbol resolution"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-fe<file>"
argument_list|,
literal|"Specify external symbol declaration file"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-in"
argument_list|,
literal|"Ignore NoOp opcodes"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-vt"
argument_list|,
literal|"Dump binary table data in hex format within output file"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\nDebug Options:\n"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-bf -bt"
argument_list|,
literal|"Create debug file (full or parse tree only) (*.txt)"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-f"
argument_list|,
literal|"Ignore errors, force creation of AML output file(s)"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-m<size>"
argument_list|,
literal|"Set internal line buffer size (in Kbytes)"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-n"
argument_list|,
literal|"Parse only, no output generation"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-ot"
argument_list|,
literal|"Display compile times and statistics"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-x<level>"
argument_list|,
literal|"Set debug level for trace output"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-z"
argument_list|,
literal|"Do not insert new compiler ID for DataTables"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    FilenameHelp  *  * PARAMETERS:  None  *  * RETURN:      None  *  * DESCRIPTION: Display help message for output filename generation  *  ******************************************************************************/
end_comment

begin_function
name|void
name|AslFilenameHelp
parameter_list|(
name|void
parameter_list|)
block|{
name|printf
argument_list|(
literal|"\nAML output filename generation:\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  Output filenames are generated by appending an extension to a common\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  filename prefix. The filename prefix is obtained via one of the\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  following methods (in priority order):\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"    1) The -p option specifies the prefix\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"    2) The prefix of the AMLFileName in the ASL Definition Block\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"    3) The prefix of the input filename\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AslSignalHandler  *  * PARAMETERS:  Sig                 - Signal that invoked this handler  *  * RETURN:      None  *  * DESCRIPTION: Control-C handler. Delete any intermediate files and any  *              output files that may be left in an indeterminate state.  *  *****************************************************************************/
end_comment

begin_function
specifier|static
name|void
name|ACPI_SYSTEM_XFACE
name|AslSignalHandler
parameter_list|(
name|int
name|Sig
parameter_list|)
block|{
name|UINT32
name|i
decl_stmt|;
name|signal
argument_list|(
name|Sig
argument_list|,
name|SIG_IGN
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Aborting\n\n"
argument_list|)
expr_stmt|;
comment|/* Close all open files */
name|Gbl_Files
index|[
name|ASL_FILE_PREPROCESSOR
index|]
operator|.
name|Handle
operator|=
name|NULL
expr_stmt|;
comment|/* the .i file is same as source file */
for|for
control|(
name|i
operator|=
name|ASL_FILE_INPUT
init|;
name|i
operator|<
name|ASL_MAX_FILE_TYPE
condition|;
name|i
operator|++
control|)
block|{
name|FlCloseFile
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
comment|/* Delete any output files */
for|for
control|(
name|i
operator|=
name|ASL_FILE_AML_OUTPUT
init|;
name|i
operator|<
name|ASL_MAX_FILE_TYPE
condition|;
name|i
operator|++
control|)
block|{
name|FlDeleteFile
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AslInitialize  *  * PARAMETERS:  None  *  * RETURN:      None  *  * DESCRIPTION: Initialize compiler globals  *  ******************************************************************************/
end_comment

begin_function
specifier|static
name|void
name|AslInitialize
parameter_list|(
name|void
parameter_list|)
block|{
name|UINT32
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|ASL_NUM_FILES
condition|;
name|i
operator|++
control|)
block|{
name|Gbl_Files
index|[
name|i
index|]
operator|.
name|Handle
operator|=
name|NULL
expr_stmt|;
name|Gbl_Files
index|[
name|i
index|]
operator|.
name|Filename
operator|=
name|NULL
expr_stmt|;
block|}
name|Gbl_Files
index|[
name|ASL_FILE_STDOUT
index|]
operator|.
name|Handle
operator|=
name|stdout
expr_stmt|;
name|Gbl_Files
index|[
name|ASL_FILE_STDOUT
index|]
operator|.
name|Filename
operator|=
literal|"STDOUT"
expr_stmt|;
name|Gbl_Files
index|[
name|ASL_FILE_STDERR
index|]
operator|.
name|Handle
operator|=
name|stderr
expr_stmt|;
name|Gbl_Files
index|[
name|ASL_FILE_STDERR
index|]
operator|.
name|Filename
operator|=
literal|"STDERR"
expr_stmt|;
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    main  *  * PARAMETERS:  Standard argc/argv  *  * RETURN:      Program termination code  *  * DESCRIPTION: C main routine for the Asl Compiler. Handle command line  *              options and begin the compile for each file on the command line  *  ******************************************************************************/
end_comment

begin_function
name|int
name|ACPI_SYSTEM_XFACE
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|ACPI_STATUS
name|Status
decl_stmt|;
name|int
name|Index1
decl_stmt|;
name|int
name|Index2
decl_stmt|;
name|int
name|ReturnStatus
init|=
literal|0
decl_stmt|;
comment|/*      * Big-endian machines are not currently supported. ACPI tables must      * be little-endian, and support for big-endian machines needs to      * be implemented.      */
if|if
condition|(
name|AcpiIsBigEndianMachine
argument_list|()
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"iASL is not currently supported on big-endian machines.\n"
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|AcpiOsInitialize
argument_list|()
expr_stmt|;
name|ACPI_DEBUG_INITIALIZE
argument_list|()
expr_stmt|;
comment|/* For debug version only */
comment|/* Initialize preprocessor and compiler before command line processing */
name|signal
argument_list|(
name|SIGINT
argument_list|,
name|AslSignalHandler
argument_list|)
expr_stmt|;
name|AcpiGbl_ExternalFileList
operator|=
name|NULL
expr_stmt|;
name|AcpiDbgLevel
operator|=
literal|0
expr_stmt|;
name|PrInitializePreprocessor
argument_list|()
expr_stmt|;
name|AslInitialize
argument_list|()
expr_stmt|;
name|Index1
operator|=
name|Index2
operator|=
name|AslCommandLine
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
expr_stmt|;
comment|/* Allocate the line buffer(s), must be after command line */
name|Gbl_LineBufferSize
operator|/=
literal|2
expr_stmt|;
name|UtExpandLineBuffers
argument_list|()
expr_stmt|;
comment|/* Perform global actions first/only */
if|if
condition|(
name|Gbl_DisassembleAll
condition|)
block|{
while|while
condition|(
name|argv
index|[
name|Index1
index|]
condition|)
block|{
name|Status
operator|=
name|AcpiDmAddToExternalFileList
argument_list|(
name|argv
index|[
name|Index1
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|ACPI_FAILURE
argument_list|(
name|Status
argument_list|)
condition|)
block|{
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|Index1
operator|++
expr_stmt|;
block|}
block|}
comment|/* Process each pathname/filename in the list, with possible wildcards */
while|while
condition|(
name|argv
index|[
name|Index2
index|]
condition|)
block|{
comment|/*          * If -p not specified, we will use the input filename as the          * output filename prefix          */
if|if
condition|(
name|Gbl_UseDefaultAmlFilename
condition|)
block|{
name|Gbl_OutputFilenamePrefix
operator|=
name|argv
index|[
name|Index2
index|]
expr_stmt|;
name|UtConvertBackslashes
argument_list|(
name|Gbl_OutputFilenamePrefix
argument_list|)
expr_stmt|;
block|}
name|Status
operator|=
name|AslDoOneFile
argument_list|(
name|argv
index|[
name|Index2
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|ACPI_FAILURE
argument_list|(
name|Status
argument_list|)
condition|)
block|{
name|ReturnStatus
operator|=
operator|-
literal|1
expr_stmt|;
goto|goto
name|CleanupAndExit
goto|;
block|}
name|Index2
operator|++
expr_stmt|;
block|}
name|CleanupAndExit
label|:
name|UtFreeLineBuffers
argument_list|()
expr_stmt|;
name|AslParserCleanup
argument_list|()
expr_stmt|;
if|if
condition|(
name|AcpiGbl_ExternalFileList
condition|)
block|{
name|AcpiDmClearExternalFileList
argument_list|()
expr_stmt|;
block|}
return|return
operator|(
name|ReturnStatus
operator|)
return|;
block|}
end_function

end_unit

