#ifndef __STATUS_CODES_H__
#define __STATUS_CODES_H__

typedef enum
{
    ok = 0,
    error_wrong_options_count = -1,
    error_wrong_option_value = -2,
    error_unrecognized_option = -3,
    error_cannot_open_input_file = -4
} status_code;

#endif