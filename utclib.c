begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: cmclib - Local implementation of C library functions  * $Revision: 1.60 $  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2007, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|__CMCLIB_C__
end_define

begin_include
include|#
directive|include
file|<contrib/dev/acpica/acpi.h>
end_include

begin_comment
comment|/*  * These implementations of standard C Library routines can optionally be  * used if a C library is not available.  In general, they are less efficient  * than an inline or assembly implementation  */
end_comment

begin_define
define|#
directive|define
name|_COMPONENT
value|ACPI_UTILITIES
end_define

begin_macro
name|ACPI_MODULE_NAME
argument_list|(
literal|"cmclib"
argument_list|)
end_macro

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_SYSTEM_CLIBRARY
end_ifndef

begin_define
define|#
directive|define
name|NEGATIVE
value|1
end_define

begin_define
define|#
directive|define
name|POSITIVE
value|0
end_define

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtMemcmp (memcmp)  *  * PARAMETERS:  Buffer1         - First Buffer  *              Buffer2         - Second Buffer  *              Count           - Maximum # of bytes to compare  *  * RETURN:      Index where Buffers mismatched, or 0 if Buffers matched  *  * DESCRIPTION: Compare two Buffers, with a maximum length  *  ******************************************************************************/
end_comment

begin_function
name|int
name|AcpiUtMemcmp
parameter_list|(
specifier|const
name|char
modifier|*
name|Buffer1
parameter_list|,
specifier|const
name|char
modifier|*
name|Buffer2
parameter_list|,
name|ACPI_SIZE
name|Count
parameter_list|)
block|{
for|for
control|(
init|;
name|Count
operator|--
operator|&&
operator|(
operator|*
name|Buffer1
operator|==
operator|*
name|Buffer2
operator|)
condition|;
name|Buffer1
operator|++
operator|,
name|Buffer2
operator|++
control|)
block|{     }
return|return
operator|(
operator|(
name|Count
operator|==
name|ACPI_SIZE_MAX
operator|)
condition|?
literal|0
else|:
operator|(
operator|(
name|unsigned
name|char
operator|)
operator|*
name|Buffer1
operator|-
operator|(
name|unsigned
name|char
operator|)
operator|*
name|Buffer2
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtMemcpy (memcpy)  *  * PARAMETERS:  Dest        - Target of the copy  *              Src         - Source buffer to copy  *              Count       - Number of bytes to copy  *  * RETURN:      Dest  *  * DESCRIPTION: Copy arbitrary bytes of memory  *  ******************************************************************************/
end_comment

begin_function
name|void
modifier|*
name|AcpiUtMemcpy
parameter_list|(
name|void
modifier|*
name|Dest
parameter_list|,
specifier|const
name|void
modifier|*
name|Src
parameter_list|,
name|ACPI_SIZE
name|Count
parameter_list|)
block|{
name|char
modifier|*
name|New
init|=
operator|(
name|char
operator|*
operator|)
name|Dest
decl_stmt|;
name|char
modifier|*
name|Old
init|=
operator|(
name|char
operator|*
operator|)
name|Src
decl_stmt|;
while|while
condition|(
name|Count
condition|)
block|{
operator|*
name|New
operator|=
operator|*
name|Old
expr_stmt|;
name|New
operator|++
expr_stmt|;
name|Old
operator|++
expr_stmt|;
name|Count
operator|--
expr_stmt|;
block|}
return|return
operator|(
name|Dest
operator|)
return|;
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtMemset (memset)  *  * PARAMETERS:  Dest        - Buffer to set  *              Value       - Value to set each byte of memory  *              Count       - Number of bytes to set  *  * RETURN:      Dest  *  * DESCRIPTION: Initialize a buffer to a known value.  *  ******************************************************************************/
end_comment

begin_function
name|void
modifier|*
name|AcpiUtMemset
parameter_list|(
name|void
modifier|*
name|Dest
parameter_list|,
name|ACPI_NATIVE_UINT
name|Value
parameter_list|,
name|ACPI_SIZE
name|Count
parameter_list|)
block|{
name|char
modifier|*
name|New
init|=
operator|(
name|char
operator|*
operator|)
name|Dest
decl_stmt|;
while|while
condition|(
name|Count
condition|)
block|{
operator|*
name|New
operator|=
operator|(
name|char
operator|)
name|Value
expr_stmt|;
name|New
operator|++
expr_stmt|;
name|Count
operator|--
expr_stmt|;
block|}
return|return
operator|(
name|Dest
operator|)
return|;
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtStrlen (strlen)  *  * PARAMETERS:  String              - Null terminated string  *  * RETURN:      Length  *  * DESCRIPTION: Returns the length of the input string  *  ******************************************************************************/
end_comment

begin_function
name|ACPI_SIZE
name|AcpiUtStrlen
parameter_list|(
specifier|const
name|char
modifier|*
name|String
parameter_list|)
block|{
name|UINT32
name|Length
init|=
literal|0
decl_stmt|;
comment|/* Count the string until a null is encountered */
while|while
condition|(
operator|*
name|String
condition|)
block|{
name|Length
operator|++
expr_stmt|;
name|String
operator|++
expr_stmt|;
block|}
return|return
operator|(
name|Length
operator|)
return|;
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtStrcpy (strcpy)  *  * PARAMETERS:  DstString       - Target of the copy  *              SrcString       - The source string to copy  *  * RETURN:      DstString  *  * DESCRIPTION: Copy a null terminated string  *  ******************************************************************************/
end_comment

begin_function
name|char
modifier|*
name|AcpiUtStrcpy
parameter_list|(
name|char
modifier|*
name|DstString
parameter_list|,
specifier|const
name|char
modifier|*
name|SrcString
parameter_list|)
block|{
name|char
modifier|*
name|String
init|=
name|DstString
decl_stmt|;
comment|/* Move bytes brute force */
while|while
condition|(
operator|*
name|SrcString
condition|)
block|{
operator|*
name|String
operator|=
operator|*
name|SrcString
expr_stmt|;
name|String
operator|++
expr_stmt|;
name|SrcString
operator|++
expr_stmt|;
block|}
comment|/* Null terminate */
operator|*
name|String
operator|=
literal|0
expr_stmt|;
return|return
operator|(
name|DstString
operator|)
return|;
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtStrncpy (strncpy)  *  * PARAMETERS:  DstString       - Target of the copy  *              SrcString       - The source string to copy  *              Count           - Maximum # of bytes to copy  *  * RETURN:      DstString  *  * DESCRIPTION: Copy a null terminated string, with a maximum length  *  ******************************************************************************/
end_comment

begin_function
name|char
modifier|*
name|AcpiUtStrncpy
parameter_list|(
name|char
modifier|*
name|DstString
parameter_list|,
specifier|const
name|char
modifier|*
name|SrcString
parameter_list|,
name|ACPI_SIZE
name|Count
parameter_list|)
block|{
name|char
modifier|*
name|String
init|=
name|DstString
decl_stmt|;
comment|/* Copy the string */
for|for
control|(
name|String
operator|=
name|DstString
init|;
name|Count
operator|&&
operator|(
name|Count
operator|--
operator|,
operator|(
operator|*
name|String
operator|++
operator|=
operator|*
name|SrcString
operator|++
operator|)
operator|)
condition|;
control|)
block|{
empty_stmt|;
block|}
comment|/* Pad with nulls if necessary */
while|while
condition|(
name|Count
operator|--
condition|)
block|{
operator|*
name|String
operator|=
literal|0
expr_stmt|;
name|String
operator|++
expr_stmt|;
block|}
comment|/* Return original pointer */
return|return
operator|(
name|DstString
operator|)
return|;
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtStrcmp (strcmp)  *  * PARAMETERS:  String1         - First string  *              String2         - Second string  *  * RETURN:      Index where strings mismatched, or 0 if strings matched  *  * DESCRIPTION: Compare two null terminated strings  *  ******************************************************************************/
end_comment

begin_function
name|int
name|AcpiUtStrcmp
parameter_list|(
specifier|const
name|char
modifier|*
name|String1
parameter_list|,
specifier|const
name|char
modifier|*
name|String2
parameter_list|)
block|{
for|for
control|(
init|;
operator|(
operator|*
name|String1
operator|==
operator|*
name|String2
operator|)
condition|;
name|String2
operator|++
control|)
block|{
if|if
condition|(
operator|!
operator|*
name|String1
operator|++
condition|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
block|}
return|return
operator|(
operator|(
name|unsigned
name|char
operator|)
operator|*
name|String1
operator|-
operator|(
name|unsigned
name|char
operator|)
operator|*
name|String2
operator|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_FUTURE_IMPLEMENTATION
end_ifdef

begin_comment
comment|/* Not used at this time */
end_comment

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtStrchr (strchr)  *  * PARAMETERS:  String          - Search string  *              ch              - character to search for  *  * RETURN:      Ptr to char or NULL if not found  *  * DESCRIPTION: Search a string for a character  *  ******************************************************************************/
end_comment

begin_function
name|char
modifier|*
name|AcpiUtStrchr
parameter_list|(
specifier|const
name|char
modifier|*
name|String
parameter_list|,
name|int
name|ch
parameter_list|)
block|{
for|for
control|(
init|;
operator|(
operator|*
name|String
operator|)
condition|;
name|String
operator|++
control|)
block|{
if|if
condition|(
operator|(
operator|*
name|String
operator|)
operator|==
operator|(
name|char
operator|)
name|ch
condition|)
block|{
return|return
operator|(
operator|(
name|char
operator|*
operator|)
name|String
operator|)
return|;
block|}
block|}
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtStrncmp (strncmp)  *  * PARAMETERS:  String1         - First string  *              String2         - Second string  *              Count           - Maximum # of bytes to compare  *  * RETURN:      Index where strings mismatched, or 0 if strings matched  *  * DESCRIPTION: Compare two null terminated strings, with a maximum length  *  ******************************************************************************/
end_comment

begin_function
name|int
name|AcpiUtStrncmp
parameter_list|(
specifier|const
name|char
modifier|*
name|String1
parameter_list|,
specifier|const
name|char
modifier|*
name|String2
parameter_list|,
name|ACPI_SIZE
name|Count
parameter_list|)
block|{
for|for
control|(
init|;
name|Count
operator|--
operator|&&
operator|(
operator|*
name|String1
operator|==
operator|*
name|String2
operator|)
condition|;
name|String2
operator|++
control|)
block|{
if|if
condition|(
operator|!
operator|*
name|String1
operator|++
condition|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
block|}
return|return
operator|(
operator|(
name|Count
operator|==
name|ACPI_SIZE_MAX
operator|)
condition|?
literal|0
else|:
operator|(
operator|(
name|unsigned
name|char
operator|)
operator|*
name|String1
operator|-
operator|(
name|unsigned
name|char
operator|)
operator|*
name|String2
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtStrcat (Strcat)  *  * PARAMETERS:  DstString       - Target of the copy  *              SrcString       - The source string to copy  *  * RETURN:      DstString  *  * DESCRIPTION: Append a null terminated string to a null terminated string  *  ******************************************************************************/
end_comment

begin_function
name|char
modifier|*
name|AcpiUtStrcat
parameter_list|(
name|char
modifier|*
name|DstString
parameter_list|,
specifier|const
name|char
modifier|*
name|SrcString
parameter_list|)
block|{
name|char
modifier|*
name|String
decl_stmt|;
comment|/* Find end of the destination string */
for|for
control|(
name|String
operator|=
name|DstString
init|;
operator|*
name|String
operator|++
condition|;
control|)
block|{
empty_stmt|;
block|}
comment|/* Concatenate the string */
for|for
control|(
operator|--
name|String
init|;
operator|(
operator|*
name|String
operator|++
operator|=
operator|*
name|SrcString
operator|++
operator|)
condition|;
control|)
block|{
empty_stmt|;
block|}
return|return
operator|(
name|DstString
operator|)
return|;
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtStrncat (strncat)  *  * PARAMETERS:  DstString       - Target of the copy  *              SrcString       - The source string to copy  *              Count           - Maximum # of bytes to copy  *  * RETURN:      DstString  *  * DESCRIPTION: Append a null terminated string to a null terminated string,  *              with a maximum count.  *  ******************************************************************************/
end_comment

begin_function
name|char
modifier|*
name|AcpiUtStrncat
parameter_list|(
name|char
modifier|*
name|DstString
parameter_list|,
specifier|const
name|char
modifier|*
name|SrcString
parameter_list|,
name|ACPI_SIZE
name|Count
parameter_list|)
block|{
name|char
modifier|*
name|String
decl_stmt|;
if|if
condition|(
name|Count
condition|)
block|{
comment|/* Find end of the destination string */
for|for
control|(
name|String
operator|=
name|DstString
init|;
operator|*
name|String
operator|++
condition|;
control|)
block|{
empty_stmt|;
block|}
comment|/* Concatenate the string */
for|for
control|(
operator|--
name|String
init|;
operator|(
operator|*
name|String
operator|++
operator|=
operator|*
name|SrcString
operator|++
operator|)
operator|&&
operator|--
name|Count
condition|;
control|)
block|{
empty_stmt|;
block|}
comment|/* Null terminate if necessary */
if|if
condition|(
operator|!
name|Count
condition|)
block|{
operator|*
name|String
operator|=
literal|0
expr_stmt|;
block|}
block|}
return|return
operator|(
name|DstString
operator|)
return|;
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtStrstr (strstr)  *  * PARAMETERS:  String1         - Target string  *              String2         - Substring to search for  *  * RETURN:      Where substring match starts, Null if no match found  *  * DESCRIPTION: Checks if String2 occurs in String1. This is not really a  *              full implementation of strstr, only sufficient for command  *              matching  *  ******************************************************************************/
end_comment

begin_function
name|char
modifier|*
name|AcpiUtStrstr
parameter_list|(
name|char
modifier|*
name|String1
parameter_list|,
name|char
modifier|*
name|String2
parameter_list|)
block|{
name|char
modifier|*
name|String
decl_stmt|;
if|if
condition|(
name|AcpiUtStrlen
argument_list|(
name|String2
argument_list|)
operator|>
name|AcpiUtStrlen
argument_list|(
name|String1
argument_list|)
condition|)
block|{
return|return
operator|(
name|NULL
operator|)
return|;
block|}
comment|/* Walk entire string, comparing the letters */
for|for
control|(
name|String
operator|=
name|String1
init|;
operator|*
name|String2
condition|;
control|)
block|{
if|if
condition|(
operator|*
name|String2
operator|!=
operator|*
name|String
condition|)
block|{
return|return
operator|(
name|NULL
operator|)
return|;
block|}
name|String2
operator|++
expr_stmt|;
name|String
operator|++
expr_stmt|;
block|}
return|return
operator|(
name|String1
operator|)
return|;
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtStrtoul (strtoul)  *  * PARAMETERS:  String          - Null terminated string  *              Terminater      - Where a pointer to the terminating byte is  *                                returned  *              Base            - Radix of the string  *  * RETURN:      Converted value  *  * DESCRIPTION: Convert a string into a 32-bit unsigned value.  *              Note: use AcpiUtStrtoul64 for 64-bit integers.  *  ******************************************************************************/
end_comment

begin_function
name|UINT32
name|AcpiUtStrtoul
parameter_list|(
specifier|const
name|char
modifier|*
name|String
parameter_list|,
name|char
modifier|*
modifier|*
name|Terminator
parameter_list|,
name|UINT32
name|Base
parameter_list|)
block|{
name|UINT32
name|converted
init|=
literal|0
decl_stmt|;
name|UINT32
name|index
decl_stmt|;
name|UINT32
name|sign
decl_stmt|;
specifier|const
name|char
modifier|*
name|StringStart
decl_stmt|;
name|UINT32
name|ReturnValue
init|=
literal|0
decl_stmt|;
name|ACPI_STATUS
name|Status
init|=
name|AE_OK
decl_stmt|;
comment|/*      * Save the value of the pointer to the buffer's first      * character, save the current errno value, and then      * skip over any white space in the buffer:      */
name|StringStart
operator|=
name|String
expr_stmt|;
while|while
condition|(
name|ACPI_IS_SPACE
argument_list|(
operator|*
name|String
argument_list|)
operator|||
operator|*
name|String
operator|==
literal|'\t'
condition|)
block|{
operator|++
name|String
expr_stmt|;
block|}
comment|/*      * The buffer may contain an optional plus or minus sign.      * If it does, then skip over it but remember what is was:      */
if|if
condition|(
operator|*
name|String
operator|==
literal|'-'
condition|)
block|{
name|sign
operator|=
name|NEGATIVE
expr_stmt|;
operator|++
name|String
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|*
name|String
operator|==
literal|'+'
condition|)
block|{
operator|++
name|String
expr_stmt|;
name|sign
operator|=
name|POSITIVE
expr_stmt|;
block|}
else|else
block|{
name|sign
operator|=
name|POSITIVE
expr_stmt|;
block|}
comment|/*      * If the input parameter Base is zero, then we need to      * determine if it is octal, decimal, or hexadecimal:      */
if|if
condition|(
name|Base
operator|==
literal|0
condition|)
block|{
if|if
condition|(
operator|*
name|String
operator|==
literal|'0'
condition|)
block|{
if|if
condition|(
name|AcpiUtToLower
argument_list|(
operator|*
operator|(
operator|++
name|String
operator|)
argument_list|)
operator|==
literal|'x'
condition|)
block|{
name|Base
operator|=
literal|16
expr_stmt|;
operator|++
name|String
expr_stmt|;
block|}
else|else
block|{
name|Base
operator|=
literal|8
expr_stmt|;
block|}
block|}
else|else
block|{
name|Base
operator|=
literal|10
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|Base
operator|<
literal|2
operator|||
name|Base
operator|>
literal|36
condition|)
block|{
comment|/*          * The specified Base parameter is not in the domain of          * this function:          */
goto|goto
name|done
goto|;
block|}
comment|/*      * For octal and hexadecimal bases, skip over the leading      * 0 or 0x, if they are present.      */
if|if
condition|(
name|Base
operator|==
literal|8
operator|&&
operator|*
name|String
operator|==
literal|'0'
condition|)
block|{
name|String
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|Base
operator|==
literal|16
operator|&&
operator|*
name|String
operator|==
literal|'0'
operator|&&
name|AcpiUtToLower
argument_list|(
operator|*
operator|(
operator|++
name|String
operator|)
argument_list|)
operator|==
literal|'x'
condition|)
block|{
name|String
operator|++
expr_stmt|;
block|}
comment|/*      * Main loop: convert the string to an unsigned long:      */
while|while
condition|(
operator|*
name|String
condition|)
block|{
if|if
condition|(
name|ACPI_IS_DIGIT
argument_list|(
operator|*
name|String
argument_list|)
condition|)
block|{
name|index
operator|=
call|(
name|UINT32
call|)
argument_list|(
operator|(
name|UINT8
operator|)
operator|*
name|String
operator|-
literal|'0'
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|index
operator|=
operator|(
name|UINT32
operator|)
name|AcpiUtToUpper
argument_list|(
operator|*
name|String
argument_list|)
expr_stmt|;
if|if
condition|(
name|ACPI_IS_UPPER
argument_list|(
name|index
argument_list|)
condition|)
block|{
name|index
operator|=
name|index
operator|-
literal|'A'
operator|+
literal|10
expr_stmt|;
block|}
else|else
block|{
goto|goto
name|done
goto|;
block|}
block|}
if|if
condition|(
name|index
operator|>=
name|Base
condition|)
block|{
goto|goto
name|done
goto|;
block|}
comment|/*          * Check to see if value is out of range:          */
if|if
condition|(
name|ReturnValue
operator|>
operator|(
operator|(
name|ACPI_UINT32_MAX
operator|-
operator|(
name|UINT32
operator|)
name|index
operator|)
operator|/
operator|(
name|UINT32
operator|)
name|Base
operator|)
condition|)
block|{
name|Status
operator|=
name|AE_ERROR
expr_stmt|;
name|ReturnValue
operator|=
literal|0
expr_stmt|;
comment|/* reset */
block|}
else|else
block|{
name|ReturnValue
operator|*=
name|Base
expr_stmt|;
name|ReturnValue
operator|+=
name|index
expr_stmt|;
name|converted
operator|=
literal|1
expr_stmt|;
block|}
operator|++
name|String
expr_stmt|;
block|}
name|done
label|:
comment|/*      * If appropriate, update the caller's pointer to the next      * unconverted character in the buffer.      */
if|if
condition|(
name|Terminator
condition|)
block|{
if|if
condition|(
name|converted
operator|==
literal|0
operator|&&
name|ReturnValue
operator|==
literal|0
operator|&&
name|String
operator|!=
name|NULL
condition|)
block|{
operator|*
name|Terminator
operator|=
operator|(
name|char
operator|*
operator|)
name|StringStart
expr_stmt|;
block|}
else|else
block|{
operator|*
name|Terminator
operator|=
operator|(
name|char
operator|*
operator|)
name|String
expr_stmt|;
block|}
block|}
if|if
condition|(
name|Status
operator|==
name|AE_ERROR
condition|)
block|{
name|ReturnValue
operator|=
name|ACPI_UINT32_MAX
expr_stmt|;
block|}
comment|/*      * If a minus sign was present, then "the conversion is negated":      */
if|if
condition|(
name|sign
operator|==
name|NEGATIVE
condition|)
block|{
name|ReturnValue
operator|=
operator|(
name|ACPI_UINT32_MAX
operator|-
name|ReturnValue
operator|)
operator|+
literal|1
expr_stmt|;
block|}
return|return
operator|(
name|ReturnValue
operator|)
return|;
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtToUpper (TOUPPER)  *  * PARAMETERS:  c           - Character to convert  *  * RETURN:      Converted character as an int  *  * DESCRIPTION: Convert character to uppercase  *  ******************************************************************************/
end_comment

begin_function
name|int
name|AcpiUtToUpper
parameter_list|(
name|int
name|c
parameter_list|)
block|{
return|return
operator|(
name|ACPI_IS_LOWER
argument_list|(
name|c
argument_list|)
condition|?
operator|(
operator|(
name|c
operator|)
operator|-
literal|0x20
operator|)
else|:
operator|(
name|c
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtToLower (TOLOWER)  *  * PARAMETERS:  c           - Character to convert  *  * RETURN:      Converted character as an int  *  * DESCRIPTION: Convert character to lowercase  *  ******************************************************************************/
end_comment

begin_function
name|int
name|AcpiUtToLower
parameter_list|(
name|int
name|c
parameter_list|)
block|{
return|return
operator|(
name|ACPI_IS_UPPER
argument_list|(
name|c
argument_list|)
condition|?
operator|(
operator|(
name|c
operator|)
operator|+
literal|0x20
operator|)
else|:
operator|(
name|c
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    is* functions  *  * DESCRIPTION: is* functions use the ctype table below  *  ******************************************************************************/
end_comment

begin_decl_stmt
specifier|const
name|UINT8
name|_acpi_ctype
index|[
literal|257
index|]
init|=
block|{
name|_ACPI_CN
block|,
comment|/* 0x0      0.     */
name|_ACPI_CN
block|,
comment|/* 0x1      1.     */
name|_ACPI_CN
block|,
comment|/* 0x2      2.     */
name|_ACPI_CN
block|,
comment|/* 0x3      3.     */
name|_ACPI_CN
block|,
comment|/* 0x4      4.     */
name|_ACPI_CN
block|,
comment|/* 0x5      5.     */
name|_ACPI_CN
block|,
comment|/* 0x6      6.     */
name|_ACPI_CN
block|,
comment|/* 0x7      7.     */
name|_ACPI_CN
block|,
comment|/* 0x8      8.     */
name|_ACPI_CN
operator||
name|_ACPI_SP
block|,
comment|/* 0x9      9.     */
name|_ACPI_CN
operator||
name|_ACPI_SP
block|,
comment|/* 0xA     10.     */
name|_ACPI_CN
operator||
name|_ACPI_SP
block|,
comment|/* 0xB     11.     */
name|_ACPI_CN
operator||
name|_ACPI_SP
block|,
comment|/* 0xC     12.     */
name|_ACPI_CN
operator||
name|_ACPI_SP
block|,
comment|/* 0xD     13.     */
name|_ACPI_CN
block|,
comment|/* 0xE     14.     */
name|_ACPI_CN
block|,
comment|/* 0xF     15.     */
name|_ACPI_CN
block|,
comment|/* 0x10    16.     */
name|_ACPI_CN
block|,
comment|/* 0x11    17.     */
name|_ACPI_CN
block|,
comment|/* 0x12    18.     */
name|_ACPI_CN
block|,
comment|/* 0x13    19.     */
name|_ACPI_CN
block|,
comment|/* 0x14    20.     */
name|_ACPI_CN
block|,
comment|/* 0x15    21.     */
name|_ACPI_CN
block|,
comment|/* 0x16    22.     */
name|_ACPI_CN
block|,
comment|/* 0x17    23.     */
name|_ACPI_CN
block|,
comment|/* 0x18    24.     */
name|_ACPI_CN
block|,
comment|/* 0x19    25.     */
name|_ACPI_CN
block|,
comment|/* 0x1A    26.     */
name|_ACPI_CN
block|,
comment|/* 0x1B    27.     */
name|_ACPI_CN
block|,
comment|/* 0x1C    28.     */
name|_ACPI_CN
block|,
comment|/* 0x1D    29.     */
name|_ACPI_CN
block|,
comment|/* 0x1E    30.     */
name|_ACPI_CN
block|,
comment|/* 0x1F    31.     */
name|_ACPI_XS
operator||
name|_ACPI_SP
block|,
comment|/* 0x20    32. ' ' */
name|_ACPI_PU
block|,
comment|/* 0x21    33. '!' */
name|_ACPI_PU
block|,
comment|/* 0x22    34. '"' */
name|_ACPI_PU
block|,
comment|/* 0x23    35. '#' */
name|_ACPI_PU
block|,
comment|/* 0x24    36. '$' */
name|_ACPI_PU
block|,
comment|/* 0x25    37. '%' */
name|_ACPI_PU
block|,
comment|/* 0x26    38. '&' */
name|_ACPI_PU
block|,
comment|/* 0x27    39. ''' */
name|_ACPI_PU
block|,
comment|/* 0x28    40. '(' */
name|_ACPI_PU
block|,
comment|/* 0x29    41. ')' */
name|_ACPI_PU
block|,
comment|/* 0x2A    42. '*' */
name|_ACPI_PU
block|,
comment|/* 0x2B    43. '+' */
name|_ACPI_PU
block|,
comment|/* 0x2C    44. ',' */
name|_ACPI_PU
block|,
comment|/* 0x2D    45. '-' */
name|_ACPI_PU
block|,
comment|/* 0x2E    46. '.' */
name|_ACPI_PU
block|,
comment|/* 0x2F    47. '/' */
name|_ACPI_XD
operator||
name|_ACPI_DI
block|,
comment|/* 0x30    48. '0' */
name|_ACPI_XD
operator||
name|_ACPI_DI
block|,
comment|/* 0x31    49. '1' */
name|_ACPI_XD
operator||
name|_ACPI_DI
block|,
comment|/* 0x32    50. '2' */
name|_ACPI_XD
operator||
name|_ACPI_DI
block|,
comment|/* 0x33    51. '3' */
name|_ACPI_XD
operator||
name|_ACPI_DI
block|,
comment|/* 0x34    52. '4' */
name|_ACPI_XD
operator||
name|_ACPI_DI
block|,
comment|/* 0x35    53. '5' */
name|_ACPI_XD
operator||
name|_ACPI_DI
block|,
comment|/* 0x36    54. '6' */
name|_ACPI_XD
operator||
name|_ACPI_DI
block|,
comment|/* 0x37    55. '7' */
name|_ACPI_XD
operator||
name|_ACPI_DI
block|,
comment|/* 0x38    56. '8' */
name|_ACPI_XD
operator||
name|_ACPI_DI
block|,
comment|/* 0x39    57. '9' */
name|_ACPI_PU
block|,
comment|/* 0x3A    58. ':' */
name|_ACPI_PU
block|,
comment|/* 0x3B    59. ';' */
name|_ACPI_PU
block|,
comment|/* 0x3C    60. '<' */
name|_ACPI_PU
block|,
comment|/* 0x3D    61. '=' */
name|_ACPI_PU
block|,
comment|/* 0x3E    62. '>' */
name|_ACPI_PU
block|,
comment|/* 0x3F    63. '?' */
name|_ACPI_PU
block|,
comment|/* 0x40    64. '@' */
name|_ACPI_XD
operator||
name|_ACPI_UP
block|,
comment|/* 0x41    65. 'A' */
name|_ACPI_XD
operator||
name|_ACPI_UP
block|,
comment|/* 0x42    66. 'B' */
name|_ACPI_XD
operator||
name|_ACPI_UP
block|,
comment|/* 0x43    67. 'C' */
name|_ACPI_XD
operator||
name|_ACPI_UP
block|,
comment|/* 0x44    68. 'D' */
name|_ACPI_XD
operator||
name|_ACPI_UP
block|,
comment|/* 0x45    69. 'E' */
name|_ACPI_XD
operator||
name|_ACPI_UP
block|,
comment|/* 0x46    70. 'F' */
name|_ACPI_UP
block|,
comment|/* 0x47    71. 'G' */
name|_ACPI_UP
block|,
comment|/* 0x48    72. 'H' */
name|_ACPI_UP
block|,
comment|/* 0x49    73. 'I' */
name|_ACPI_UP
block|,
comment|/* 0x4A    74. 'J' */
name|_ACPI_UP
block|,
comment|/* 0x4B    75. 'K' */
name|_ACPI_UP
block|,
comment|/* 0x4C    76. 'L' */
name|_ACPI_UP
block|,
comment|/* 0x4D    77. 'M' */
name|_ACPI_UP
block|,
comment|/* 0x4E    78. 'N' */
name|_ACPI_UP
block|,
comment|/* 0x4F    79. 'O' */
name|_ACPI_UP
block|,
comment|/* 0x50    80. 'P' */
name|_ACPI_UP
block|,
comment|/* 0x51    81. 'Q' */
name|_ACPI_UP
block|,
comment|/* 0x52    82. 'R' */
name|_ACPI_UP
block|,
comment|/* 0x53    83. 'S' */
name|_ACPI_UP
block|,
comment|/* 0x54    84. 'T' */
name|_ACPI_UP
block|,
comment|/* 0x55    85. 'U' */
name|_ACPI_UP
block|,
comment|/* 0x56    86. 'V' */
name|_ACPI_UP
block|,
comment|/* 0x57    87. 'W' */
name|_ACPI_UP
block|,
comment|/* 0x58    88. 'X' */
name|_ACPI_UP
block|,
comment|/* 0x59    89. 'Y' */
name|_ACPI_UP
block|,
comment|/* 0x5A    90. 'Z' */
name|_ACPI_PU
block|,
comment|/* 0x5B    91. '[' */
name|_ACPI_PU
block|,
comment|/* 0x5C    92. '\' */
name|_ACPI_PU
block|,
comment|/* 0x5D    93. ']' */
name|_ACPI_PU
block|,
comment|/* 0x5E    94. '^' */
name|_ACPI_PU
block|,
comment|/* 0x5F    95. '_' */
name|_ACPI_PU
block|,
comment|/* 0x60    96. '`' */
name|_ACPI_XD
operator||
name|_ACPI_LO
block|,
comment|/* 0x61    97. 'a' */
name|_ACPI_XD
operator||
name|_ACPI_LO
block|,
comment|/* 0x62    98. 'b' */
name|_ACPI_XD
operator||
name|_ACPI_LO
block|,
comment|/* 0x63    99. 'c' */
name|_ACPI_XD
operator||
name|_ACPI_LO
block|,
comment|/* 0x64   100. 'd' */
name|_ACPI_XD
operator||
name|_ACPI_LO
block|,
comment|/* 0x65   101. 'e' */
name|_ACPI_XD
operator||
name|_ACPI_LO
block|,
comment|/* 0x66   102. 'f' */
name|_ACPI_LO
block|,
comment|/* 0x67   103. 'g' */
name|_ACPI_LO
block|,
comment|/* 0x68   104. 'h' */
name|_ACPI_LO
block|,
comment|/* 0x69   105. 'i' */
name|_ACPI_LO
block|,
comment|/* 0x6A   106. 'j' */
name|_ACPI_LO
block|,
comment|/* 0x6B   107. 'k' */
name|_ACPI_LO
block|,
comment|/* 0x6C   108. 'l' */
name|_ACPI_LO
block|,
comment|/* 0x6D   109. 'm' */
name|_ACPI_LO
block|,
comment|/* 0x6E   110. 'n' */
name|_ACPI_LO
block|,
comment|/* 0x6F   111. 'o' */
name|_ACPI_LO
block|,
comment|/* 0x70   112. 'p' */
name|_ACPI_LO
block|,
comment|/* 0x71   113. 'q' */
name|_ACPI_LO
block|,
comment|/* 0x72   114. 'r' */
name|_ACPI_LO
block|,
comment|/* 0x73   115. 's' */
name|_ACPI_LO
block|,
comment|/* 0x74   116. 't' */
name|_ACPI_LO
block|,
comment|/* 0x75   117. 'u' */
name|_ACPI_LO
block|,
comment|/* 0x76   118. 'v' */
name|_ACPI_LO
block|,
comment|/* 0x77   119. 'w' */
name|_ACPI_LO
block|,
comment|/* 0x78   120. 'x' */
name|_ACPI_LO
block|,
comment|/* 0x79   121. 'y' */
name|_ACPI_LO
block|,
comment|/* 0x7A   122. 'z' */
name|_ACPI_PU
block|,
comment|/* 0x7B   123. '{' */
name|_ACPI_PU
block|,
comment|/* 0x7C   124. '|' */
name|_ACPI_PU
block|,
comment|/* 0x7D   125. '}' */
name|_ACPI_PU
block|,
comment|/* 0x7E   126. '~' */
name|_ACPI_CN
block|,
comment|/* 0x7F   127.     */
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/* 0x80 to 0x8F    */
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/* 0x90 to 0x9F    */
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/* 0xA0 to 0xAF    */
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/* 0xB0 to 0xBF    */
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/* 0xC0 to 0xCF    */
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/* 0xD0 to 0xDF    */
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
comment|/* 0xE0 to 0xEF    */
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
comment|/* 0xF0 to 0x100   */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_USE_SYSTEM_CLIBRARY */
end_comment

end_unit

