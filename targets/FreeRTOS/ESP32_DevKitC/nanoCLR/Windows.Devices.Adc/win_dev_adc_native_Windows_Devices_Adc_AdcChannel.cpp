//
// Copyright (c) 2017 The nanoFramework project contributors
// Portions Copyright (c) Microsoft Corporation.  All rights reserved.
// See LICENSE file in the project root for full license information.
//

#include "win_dev_adc_native.h"


HRESULT Library_win_dev_adc_native_Windows_Devices_Adc_AdcChannel::NativeReadValue___I4__I4( CLR_RT_StackFrame& stack )
{
    NANOCLR_HEADER();
    {
        int reading = 0;
        esp_err_t result;

        // get a pointer to the managed object instance and check that it's not NULL
        CLR_RT_HeapBlock* pThis = stack.This();  FAULT_ON_NULL(pThis);

        // Get channel from argument
        int channelNumber = stack.Arg1().NumericByRef().s4;

        // need to get the deviceId for the ADC controller of this channel
        // get pointer to AdcController field
        CLR_RT_HeapBlock* adcController = pThis[FIELD___adcController].Dereference();

        // get pointer to _deviceId field
        int adcNumber = adcController[Library_win_dev_adc_native_Windows_Devices_Adc_AdcController::FIELD___deviceId].NumericByRef().s4;

        if ( adcNumber == 1)
        {
            if ( channelNumber == 9 ) 
                reading = hall_sensor_read();
            else
                reading = adc1_get_raw( (adc1_channel_t)channelNumber); 
        }
        else if ( adcNumber == 2)
        {
            result = adc2_get_raw( (adc2_channel_t)channelNumber, ADC_WIDTH_12Bit, &reading); 
            if ( result != ESP_OK)
                NANOCLR_SET_AND_LEAVE(CLR_E_PIN_UNAVAILABLE);
        }
        else
            NANOCLR_SET_AND_LEAVE(CLR_E_INVALID_PARAMETER);
        
       stack.SetResult_I4(reading);
 
    }
    NANOCLR_NOCLEANUP();
}

HRESULT Library_win_dev_adc_native_Windows_Devices_Adc_AdcChannel::NativeDisposeChannel___VOID__I4( CLR_RT_StackFrame& stack )
{
    NANOCLR_HEADER();


    NANOCLR_NOCLEANUP();
}