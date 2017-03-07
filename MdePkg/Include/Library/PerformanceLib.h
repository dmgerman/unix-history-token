begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Provides services to log the execution times and retrieve them later.  Copyright (c) 2006 - 2016, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PERFORMANCE_LIB_H__
end_ifndef

begin_define
define|#
directive|define
name|__PERFORMANCE_LIB_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Performance library propery mask bits
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|PERFORMANCE_LIBRARY_PROPERTY_MEASUREMENT_ENABLED
value|0x00000001
end_define

begin_comment
comment|/**   Creates a record for the beginning of a performance measurement.       Creates a record that contains the Handle, Token, and Module.   If TimeStamp is not zero, then TimeStamp is added to the record as the start time.   If TimeStamp is zero, then this function reads the current time stamp   and adds that time stamp value to the record as the start time.    @param  Handle                  Pointer to environment specific context used                                   to identify the component being measured.   @param  Token                   Pointer to a Null-terminated ASCII string                                   that identifies the component being measured.   @param  Module                  Pointer to a Null-terminated ASCII string                                   that identifies the module being measured.   @param  TimeStamp               64-bit time stamp.    @retval RETURN_SUCCESS          The start of the measurement was recorded.   @retval RETURN_OUT_OF_RESOURCES There are not enough resources to record the measurement.   @retval RETURN_DEVICE_ERROR     A device error reading the time stamp.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|StartPerformanceMeasurement
parameter_list|(
name|IN
name|CONST
name|VOID
modifier|*
name|Handle
parameter_list|,
name|OPTIONAL
name|IN
name|CONST
name|CHAR8
modifier|*
name|Token
parameter_list|,
name|OPTIONAL
name|IN
name|CONST
name|CHAR8
modifier|*
name|Module
parameter_list|,
name|OPTIONAL
name|IN
name|UINT64
name|TimeStamp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Fills in the end time of a performance measurement.       Looks up the record that matches Handle, Token, and Module.   If the record can not be found then return RETURN_NOT_FOUND.   If the record is found and TimeStamp is not zero,   then TimeStamp is added to the record as the end time.   If the record is found and TimeStamp is zero, then this function reads   the current time stamp and adds that time stamp value to the record as the end time.    @param  Handle                  Pointer to environment specific context used                                   to identify the component being measured.   @param  Token                   Pointer to a Null-terminated ASCII string                                   that identifies the component being measured.   @param  Module                  Pointer to a Null-terminated ASCII string                                   that identifies the module being measured.   @param  TimeStamp               64-bit time stamp.    @retval RETURN_SUCCESS          The end of  the measurement was recorded.   @retval RETURN_NOT_FOUND        The specified measurement record could not be found.   @retval RETURN_DEVICE_ERROR     A device error reading the time stamp.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|EndPerformanceMeasurement
parameter_list|(
name|IN
name|CONST
name|VOID
modifier|*
name|Handle
parameter_list|,
name|OPTIONAL
name|IN
name|CONST
name|CHAR8
modifier|*
name|Token
parameter_list|,
name|OPTIONAL
name|IN
name|CONST
name|CHAR8
modifier|*
name|Module
parameter_list|,
name|OPTIONAL
name|IN
name|UINT64
name|TimeStamp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Attempts to retrieve a performance measurement log entry from the performance measurement log.    It can also retrieve the log created by StartPerformanceMeasurementEx and EndPerformanceMeasurementEx,   and then eliminate the Identifier.    Attempts to retrieve the performance log entry specified by LogEntryKey.  If LogEntryKey is   zero on entry, then an attempt is made to retrieve the first entry from the performance log,   and the key for the second entry in the log is returned.  If the performance log is empty,   then no entry is retrieved and zero is returned.  If LogEntryKey is not zero, then the performance   log entry associated with LogEntryKey is retrieved, and the key for the next entry in the log is   returned.  If LogEntryKey is the key for the last entry in the log, then the last log entry is   retrieved and an implementation specific non-zero key value that specifies the end of the performance   log is returned.  If LogEntryKey is equal this implementation specific non-zero key value, then no entry   is retrieved and zero is returned.  In the cases where a performance log entry can be returned,   the log entry is returned in Handle, Token, Module, StartTimeStamp, and EndTimeStamp.   If LogEntryKey is not a valid log entry key for the performance measurement log, then ASSERT().   If Handle is NULL, then ASSERT().   If Token is NULL, then ASSERT().   If Module is NULL, then ASSERT().   If StartTimeStamp is NULL, then ASSERT().   If EndTimeStamp is NULL, then ASSERT().    @param  LogEntryKey             On entry, the key of the performance measurement log entry to retrieve.                                   0, then the first performance measurement log entry is retrieved.                                   On exit, the key of the next performance lof entry entry.   @param  Handle                  Pointer to environment specific context used to identify the component                                   being measured.     @param  Token                   Pointer to a Null-terminated ASCII string that identifies the component                                   being measured.    @param  Module                  Pointer to a Null-terminated ASCII string that identifies the module                                   being measured.   @param  StartTimeStamp          Pointer to the 64-bit time stamp that was recorded when the measurement                                   was started.   @param  EndTimeStamp            Pointer to the 64-bit time stamp that was recorded when the measurement                                   was ended.    @return The key for the next performance log entry (in general case).  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|GetPerformanceMeasurement
parameter_list|(
name|IN
name|UINTN
name|LogEntryKey
parameter_list|,
name|OUT
name|CONST
name|VOID
modifier|*
modifier|*
name|Handle
parameter_list|,
name|OUT
name|CONST
name|CHAR8
modifier|*
modifier|*
name|Token
parameter_list|,
name|OUT
name|CONST
name|CHAR8
modifier|*
modifier|*
name|Module
parameter_list|,
name|OUT
name|UINT64
modifier|*
name|StartTimeStamp
parameter_list|,
name|OUT
name|UINT64
modifier|*
name|EndTimeStamp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Creates a record for the beginning of a performance measurement.    Creates a record that contains the Handle, Token, Module and Identifier.   If TimeStamp is not zero, then TimeStamp is added to the record as the start time.   If TimeStamp is zero, then this function reads the current time stamp   and adds that time stamp value to the record as the start time.    @param  Handle                  Pointer to environment specific context used                                   to identify the component being measured.   @param  Token                   Pointer to a Null-terminated ASCII string                                   that identifies the component being measured.   @param  Module                  Pointer to a Null-terminated ASCII string                                   that identifies the module being measured.   @param  TimeStamp               64-bit time stamp.   @param  Identifier              32-bit identifier. If the value is 0, the created record                                   is same as the one created by StartPerformanceMeasurement.    @retval RETURN_SUCCESS          The start of the measurement was recorded.   @retval RETURN_OUT_OF_RESOURCES There are not enough resources to record the measurement.   @retval RETURN_DEVICE_ERROR     A device error reading the time stamp.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|StartPerformanceMeasurementEx
parameter_list|(
name|IN
name|CONST
name|VOID
modifier|*
name|Handle
parameter_list|,
name|OPTIONAL
name|IN
name|CONST
name|CHAR8
modifier|*
name|Token
parameter_list|,
name|OPTIONAL
name|IN
name|CONST
name|CHAR8
modifier|*
name|Module
parameter_list|,
name|OPTIONAL
name|IN
name|UINT64
name|TimeStamp
parameter_list|,
name|IN
name|UINT32
name|Identifier
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Fills in the end time of a performance measurement.    Looks up the record that matches Handle, Token and Module.   If the record can not be found then return RETURN_NOT_FOUND.   If the record is found and TimeStamp is not zero,   then TimeStamp is added to the record as the end time.   If the record is found and TimeStamp is zero, then this function reads   the current time stamp and adds that time stamp value to the record as the end time.    @param  Handle                  Pointer to environment specific context used                                   to identify the component being measured.   @param  Token                   Pointer to a Null-terminated ASCII string                                   that identifies the component being measured.   @param  Module                  Pointer to a Null-terminated ASCII string                                   that identifies the module being measured.   @param  TimeStamp               64-bit time stamp.   @param  Identifier              32-bit identifier. If the value is 0, the found record                                   is same as the one found by EndPerformanceMeasurement.    @retval RETURN_SUCCESS          The end of  the measurement was recorded.   @retval RETURN_NOT_FOUND        The specified measurement record could not be found.   @retval RETURN_DEVICE_ERROR     A device error reading the time stamp.  **/
end_comment

begin_function_decl
name|RETURN_STATUS
name|EFIAPI
name|EndPerformanceMeasurementEx
parameter_list|(
name|IN
name|CONST
name|VOID
modifier|*
name|Handle
parameter_list|,
name|OPTIONAL
name|IN
name|CONST
name|CHAR8
modifier|*
name|Token
parameter_list|,
name|OPTIONAL
name|IN
name|CONST
name|CHAR8
modifier|*
name|Module
parameter_list|,
name|OPTIONAL
name|IN
name|UINT64
name|TimeStamp
parameter_list|,
name|IN
name|UINT32
name|Identifier
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Attempts to retrieve a performance measurement log entry from the performance measurement log.   It can also retrieve the log created by StartPerformanceMeasurement and EndPerformanceMeasurement,   and then assign the Identifier with 0.    Attempts to retrieve the performance log entry specified by LogEntryKey.  If LogEntryKey is   zero on entry, then an attempt is made to retrieve the first entry from the performance log,   and the key for the second entry in the log is returned.  If the performance log is empty,   then no entry is retrieved and zero is returned.  If LogEntryKey is not zero, then the performance   log entry associated with LogEntryKey is retrieved, and the key for the next entry in the log is   returned.  If LogEntryKey is the key for the last entry in the log, then the last log entry is   retrieved and an implementation specific non-zero key value that specifies the end of the performance   log is returned.  If LogEntryKey is equal this implementation specific non-zero key value, then no entry   is retrieved and zero is returned.  In the cases where a performance log entry can be returned,   the log entry is returned in Handle, Token, Module, StartTimeStamp, EndTimeStamp and Identifier.   If LogEntryKey is not a valid log entry key for the performance measurement log, then ASSERT().   If Handle is NULL, then ASSERT().   If Token is NULL, then ASSERT().   If Module is NULL, then ASSERT().   If StartTimeStamp is NULL, then ASSERT().   If EndTimeStamp is NULL, then ASSERT().   If Identifier is NULL, then ASSERT().    @param  LogEntryKey             On entry, the key of the performance measurement log entry to retrieve.                                   0, then the first performance measurement log entry is retrieved.                                   On exit, the key of the next performance of entry entry.   @param  Handle                  Pointer to environment specific context used to identify the component                                   being measured.   @param  Token                   Pointer to a Null-terminated ASCII string that identifies the component                                   being measured.   @param  Module                  Pointer to a Null-terminated ASCII string that identifies the module                                   being measured.   @param  StartTimeStamp          Pointer to the 64-bit time stamp that was recorded when the measurement                                   was started.   @param  EndTimeStamp            Pointer to the 64-bit time stamp that was recorded when the measurement                                   was ended.   @param  Identifier              Pointer to the 32-bit identifier that was recorded.    @return The key for the next performance log entry (in general case).  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|GetPerformanceMeasurementEx
parameter_list|(
name|IN
name|UINTN
name|LogEntryKey
parameter_list|,
name|OUT
name|CONST
name|VOID
modifier|*
modifier|*
name|Handle
parameter_list|,
name|OUT
name|CONST
name|CHAR8
modifier|*
modifier|*
name|Token
parameter_list|,
name|OUT
name|CONST
name|CHAR8
modifier|*
modifier|*
name|Module
parameter_list|,
name|OUT
name|UINT64
modifier|*
name|StartTimeStamp
parameter_list|,
name|OUT
name|UINT64
modifier|*
name|EndTimeStamp
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|Identifier
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Returns TRUE if the performance measurement macros are enabled.       This function returns TRUE if the PERFORMANCE_LIBRARY_PROPERTY_MEASUREMENT_ENABLED bit of   PcdPerformanceLibraryPropertyMask is set.  Otherwise FALSE is returned.    @retval TRUE                    The PERFORMANCE_LIBRARY_PROPERTY_MEASUREMENT_ENABLED bit of                                   PcdPerformanceLibraryPropertyMask is set.   @retval FALSE                   The PERFORMANCE_LIBRARY_PROPERTY_MEASUREMENT_ENABLED bit of                                   PcdPerformanceLibraryPropertyMask is clear.  **/
end_comment

begin_function_decl
name|BOOLEAN
name|EFIAPI
name|PerformanceMeasurementEnabled
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Macro that calls EndPerformanceMeasurement().    If the PERFORMANCE_LIBRARY_PROPERTY_MEASUREMENT_ENABLED bit of PcdPerformanceLibraryPropertyMask is set,   then EndPerformanceMeasurement() is called.  **/
end_comment

begin_define
define|#
directive|define
name|PERF_END
parameter_list|(
name|Handle
parameter_list|,
name|Token
parameter_list|,
name|Module
parameter_list|,
name|TimeStamp
parameter_list|)
define|\
value|do {                                                                \     if (PerformanceMeasurementEnabled ()) {                           \       EndPerformanceMeasurement (Handle, Token, Module, TimeStamp);   \     }                                                                 \   } while (FALSE)
end_define

begin_comment
comment|/**   Macro that calls StartPerformanceMeasurement().    If the PERFORMANCE_LIBRARY_PROPERTY_MEASUREMENT_ENABLED bit of PcdPerformanceLibraryPropertyMask is set,   then StartPerformanceMeasurement() is called.  **/
end_comment

begin_define
define|#
directive|define
name|PERF_START
parameter_list|(
name|Handle
parameter_list|,
name|Token
parameter_list|,
name|Module
parameter_list|,
name|TimeStamp
parameter_list|)
define|\
value|do {                                                                \     if (PerformanceMeasurementEnabled ()) {                           \       StartPerformanceMeasurement (Handle, Token, Module, TimeStamp); \     }                                                                 \   } while (FALSE)
end_define

begin_comment
comment|/**   Macro that calls EndPerformanceMeasurementEx().    If the PERFORMANCE_LIBRARY_PROPERTY_MEASUREMENT_ENABLED bit of PcdPerformanceLibraryPropertyMask is set,   then EndPerformanceMeasurementEx() is called.  **/
end_comment

begin_define
define|#
directive|define
name|PERF_END_EX
parameter_list|(
name|Handle
parameter_list|,
name|Token
parameter_list|,
name|Module
parameter_list|,
name|TimeStamp
parameter_list|,
name|Identifier
parameter_list|)
define|\
value|do {                                                                              \     if (PerformanceMeasurementEnabled ()) {                                         \       EndPerformanceMeasurementEx (Handle, Token, Module, TimeStamp, Identifier);   \     }                                                                               \   } while (FALSE)
end_define

begin_comment
comment|/**   Macro that calls StartPerformanceMeasurementEx().    If the PERFORMANCE_LIBRARY_PROPERTY_MEASUREMENT_ENABLED bit of PcdPerformanceLibraryPropertyMask is set,   then StartPerformanceMeasurementEx() is called.  **/
end_comment

begin_define
define|#
directive|define
name|PERF_START_EX
parameter_list|(
name|Handle
parameter_list|,
name|Token
parameter_list|,
name|Module
parameter_list|,
name|TimeStamp
parameter_list|,
name|Identifier
parameter_list|)
define|\
value|do {                                                                              \     if (PerformanceMeasurementEnabled ()) {                                         \       StartPerformanceMeasurementEx (Handle, Token, Module, TimeStamp, Identifier); \     }                                                                               \   } while (FALSE)
end_define

begin_comment
comment|/**   Macro that marks the beginning of performance measurement source code.    If the PERFORMANCE_LIBRARY_PROPERTY_MEASUREMENT_ENABLED bit of PcdPerformanceLibraryPropertyMask is set,   then this macro marks the beginning of source code that is included in a module.   Otherwise, the source lines between PERF_CODE_BEGIN() and PERF_CODE_END() are not included in a module.  **/
end_comment

begin_define
define|#
directive|define
name|PERF_CODE_BEGIN
parameter_list|()
value|do { if (PerformanceMeasurementEnabled ()) { UINT8  __PerformanceCodeLocal
end_define

begin_comment
comment|/**   Macro that marks the end of performance measurement source code.    If the PERFORMANCE_LIBRARY_PROPERTY_MEASUREMENT_ENABLED bit of PcdPerformanceLibraryPropertyMask is set,   then this macro marks the end of source code that is included in a module.   Otherwise, the source lines between PERF_CODE_BEGIN() and PERF_CODE_END() are not included in a module.  **/
end_comment

begin_define
define|#
directive|define
name|PERF_CODE_END
parameter_list|()
value|__PerformanceCodeLocal = 0; __PerformanceCodeLocal++; } } while (FALSE)
end_define

begin_comment
comment|/**   Macro that declares a section of performance measurement source code.    If the PERFORMANCE_LIBRARY_PROPERTY_MEASUREMENT_ENABLED bit of PcdPerformanceLibraryPropertyMask is set,   then the source code specified by Expression is included in a module.   Otherwise, the source specified by Expression is not included in a module.    @param  Expression              Performance measurement source code to include in a module.  **/
end_comment

begin_define
define|#
directive|define
name|PERF_CODE
parameter_list|(
name|Expression
parameter_list|)
define|\
value|PERF_CODE_BEGIN ();          \   Expression                   \   PERF_CODE_END ()
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

