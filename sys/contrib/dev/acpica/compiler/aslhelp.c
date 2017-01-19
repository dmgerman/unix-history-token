begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: aslhelp - iASL help screens  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2017, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_include
include|#
directive|include
file|<contrib/dev/acpica/compiler/aslcompiler.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/acapps.h>
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
literal|"aslhelp"
argument_list|)
end_macro

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
literal|"-hd"
argument_list|,
literal|"Info for obtaining and disassembling binary ACPI tables"
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
literal|"-w<1|2|3>"
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
literal|"-ot"
argument_list|,
literal|"Disable typechecking"
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
literal|"\nListings:\n"
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
name|ACPI_OPTION
argument_list|(
literal|"-lx"
argument_list|,
literal|"Create cross-reference file (*.xrf)"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\nFirmware Support - C Output:\n"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-tc"
argument_list|,
literal|"Create hex AML table in C (*.hex)"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-sc"
argument_list|,
literal|"Create named hex AML arrays in C (*.c)"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-ic"
argument_list|,
literal|"Create include file in C for -sc symbols (*.h)"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-so"
argument_list|,
literal|"Create namespace AML offset table in C (*.offset.h)"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\nFirmware Support - Assembler Output:\n"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-ta"
argument_list|,
literal|"Create hex AML table in assembler (*.hex)"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-sa"
argument_list|,
literal|"Create named hex AML arrays in assembler (*.asm)"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-ia"
argument_list|,
literal|"Create include file in assembler for -sa symbols (*.inc)"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\nFirmware Support - ASL Output:\n"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-ts"
argument_list|,
literal|"Create hex AML table in ASL (Buffer object) (*.hex)"
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
literal|"-T<sig list>|ALL"
argument_list|,
literal|"Create ACPI table template/example files"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-T<count>"
argument_list|,
literal|"Emit DSDT and<count> SSDTs to same file"
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
literal|"-df"
argument_list|,
literal|"Force disassembler to assume table contains valid AML"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-dl"
argument_list|,
literal|"Emit legacy ASL code only (no C-style operators)"
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
literal|"-l"
argument_list|,
literal|"Disassemble to mixed ASL and AML code"
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
literal|"-bf"
argument_list|,
literal|"Create debug file (full output) (*.txt)"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-bs"
argument_list|,
literal|"Create debug file (parse tree only) (*.txt)"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-bp<depth>"
argument_list|,
literal|"Prune ASL parse tree"
argument_list|)
expr_stmt|;
name|ACPI_OPTION
argument_list|(
literal|"-bt<type>"
argument_list|,
literal|"Object type to be pruned from the parse tree"
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
literal|"-oc"
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
comment|/*******************************************************************************  *  * FUNCTION:    AslDisassemblyHelp  *  * PARAMETERS:  None  *  * RETURN:      None  *  * DESCRIPTION: Display help message for obtaining and disassembling AML/ASL  *              files.  *  ******************************************************************************/
end_comment

begin_function
name|void
name|AslDisassemblyHelp
parameter_list|(
name|void
parameter_list|)
block|{
name|printf
argument_list|(
literal|"\nObtaining binary ACPI tables and disassembling to ASL source code.\n\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Use the following ACPICA toolchain:\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  AcpiDump: Dump all ACPI tables to a hex ascii file\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  AcpiXtract: Extract one or more binary ACPI tables from AcpiDump output\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  iASL -d<file>: Disassemble a binary ACPI table to ASL source code\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

