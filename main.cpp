#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include  <time.h>
#include "container/container.h"
#include "objects/number.h"

#define HELP_MESSAGE    "HSE UNIVERSITY, 2021-2022, Kulikov Bogdan, first project program.\n"               \
                        "Task: 11, Function: 10\n"                                                          \
                        "\n"                                                                                \
                        "Usage: program [OPTIONS]...\n"                                                     \
                        "\n"                                                                                \
                        "OPTIONS:\n"                                                                        \
                        " -i, --input\t\t Specify input file\n"                                             \
                        " -o, --output\t\t Specify output file\n"                                           \
                        "\t\t\t\t if file does not exist - program will create one\n"                       \
                        " -r, --random\t\t Generate random input. Range [1, 10000]\n"                       \
                        " --random-input\t\t Create file with generated input\n"                            \
                        "\n"                                                                                \
                        "\n"                                                                                \
                        "INPUT SPECIFICATION:\n"                                                            \
                        "Input file starts with number of elements (int_32)\n"                              \
                        "Elements consist of fields:\n"                                                     \
                        "\t `element_type`: 0 - COMPLEX, 1 - FRACTION, 2 - POLAR\n"                         \
                        "\t `element_description`:\n"                                                       \
                        "\t\t COMPLEX: A pair of double numbers - real and imaginary parts.\n"              \
                        "\t\t\t  example: `10.1 12.0` -> complex: (real=10.1, imaginary=12.0)\n"            \
                        "\t\t FRACTION: A pair of int_32 numbers - numerator and denominator.\n"            \
                        "\t\t\t  example: `1 2` -> fraction: 1/2\n"                                         \
                        "\t\t POLAR: A Double number - angle and a pair of int_32 numbers - coordinates.\n" \
                        "\t\t\t  example: `10.1 3 4` -> polar: (angle=10.1, coords=(x=3,y=4))\n"            \
                        "See example at /tests/example.txt"                                                 \

#define ARGC_EXCEPTION_MESSAGE  "Incorrect program input\n" \
                                "Try 'program --help(-h)' for more information."

#define INPUT_FLAG_EXCEPTION_MESSAGE    "Input flag was not specified\n" \
                                        "Try 'program --help(-h)' for more information.\n"

#define OUTPUT_FLAG_EXCEPTION_MESSAGE    "Output flag was not specified\n" \
                                         "Try 'program --help(-h)' for more information.\n"

#define RANDOM_INPUT_EXCEPTION_MESSAGE "Random input file was not specified\n" \
                                        "Try 'program --help(-h)' for more information.\n"


#define INPUT_FLAG_NOT_EXISTS_MESSAGE "Input file does not exists\n"

/*
 * Флаги программы.
 */
const char* kHelpFlags[] = {"-h", "--help"};
const int kHelpFlagsCount = 2;

const char* kInputFlags[] = {"-i", "--input"};
const int kInputFlagsCount = 2;

const char* kOutputFlags[] = {"-o", "--output"};
const int kOutputFlagsCount = 2;

const char* kRandomFlags[] = {"-r", "--random"};
const int kRandomFlagsCount = 2;

const char* kRandomInputFlags[] = {"--random-input"};
const int kRandomInputFlagsCount = 1;

// Глобальный код ошибки.
int error_code;

// Проверить, если флаг верен.
bool is_flag_valid(const char* input, const char** possible_flags, int number_of_possible_flags){
    for (int i = 0; i < number_of_possible_flags; ++i) {
        if (strcmp(input, possible_flags[i]) == 0)
            return true;
    }
    return false;
}

// Найти флаг в argv.
int find_flag(int argc, char* argv[], const char** possible_flags, int number_of_flags){
    for (int i = 0; i <argc; ++i){
        if (is_flag_valid(argv[i], possible_flags, number_of_flags))
            return i;
    }
    return -1;
}

// Открыть файл с входными данными.
FILE* get_input_file(int argc, char* argv[], const char* modes = "r"){
    int input_flag_pos = find_flag(argc, argv, kInputFlags, kInputFlagsCount);

    if (input_flag_pos != -1) {
        if (input_flag_pos + 1 < argc) {
            if (access(argv[input_flag_pos + 1], F_OK) != -1)
                return fopen(argv[input_flag_pos + 1], modes);
            else{
                printf(INPUT_FLAG_NOT_EXISTS_MESSAGE);
                exit(1);
            }
        }
    }

    printf(INPUT_FLAG_EXCEPTION_MESSAGE);
    exit(1);
}

// Открыть файл для записи результатов.
FILE* get_output_file(int argc, char* argv[], const char* modes = "w"){
    int output_flag_pos = find_flag(argc, argv, kOutputFlags, kOutputFlagsCount);
    if (output_flag_pos != -1) {
        if (output_flag_pos + 1 < argc) {
                return fopen(argv[output_flag_pos + 1], modes);
        }
    }

    printf(OUTPUT_FLAG_EXCEPTION_MESSAGE);
    exit(1);
}

// Открыть файл для записи рандомного ввода.
FILE* get_random_input_file(int argc, char* argv[]){
    int random_input_file = find_flag(argc, argv, kRandomInputFlags, kRandomInputFlagsCount);
    if (random_input_file != -1){

        if (random_input_file + 1 < argc){
            return fopen(argv[random_input_file + 1], "w");
        }else{
            printf(RANDOM_INPUT_EXCEPTION_MESSAGE);
            exit(1);
        }
    }
    return NULL;
}

// Пропарсить флаг с размером рандомного ввода.
int get_random_size(int argc, char* argv[]){
    int random_flag_pos = find_flag(argc, argv, kRandomFlags, kRandomFlagsCount);
    if (random_flag_pos == -1){
        return -1;
    }

    if (argc <= random_flag_pos){
        printf("'-r' flag has no value\n");
        exit(1);
    }

    int size = atoi(argv[random_flag_pos+1]);

    if (size <= 0){
        printf("Size could not be negative or 0\n");
        exit(1);
    }
    return size;
}

// Точка входа.
int main(int argc, char* argv[]){
    time_t start, end;

    start = clock();

    if (argc < 5){
        if (argc == 2) {
            if (is_flag_valid(argv[1], kHelpFlags, kHelpFlagsCount)) {
                printf(HELP_MESSAGE);
                exit(0);
            }
        }
        printf(ARGC_EXCEPTION_MESSAGE);
        exit(1);
    }

    printf("Initializing program\n");
    container* ct = Ctor();
    FILE *output_file = get_output_file(argc, argv);

    int random_size = get_random_size(argc, argv);

    if (random_size == -1){
        FILE *input_file = get_input_file(argc, argv);
        error_code = Fill(ct, input_file);
        fclose(input_file);
        printf("Parsed input\n");
    }else{
        srand(static_cast<unsigned int>(time(0)));
        FILE* random_input_file = get_random_input_file(argc, argv);
        error_code = RandomFill(ct, random_size, random_input_file);
        printf("Generated input\n");

        if (random_input_file)
            fclose(random_input_file);
    }

    if (error_code){
        printf("Error occurred\n");
        return error_code;
    }

    Out(ct, output_file);

    fprintf(output_file, "=======================\n\n");
    fprintf(output_file, "number of elements: %d\n", ct->length);
    fprintf(output_file, "\n====| Straight Sort results | ====\n\n");

    printf("Sorting elements\n");
    StraightSort(ct);

    Out(ct, output_file);

    printf("Exiting program\n");
    Dtor(ct);
    ct = NULL;

    fclose(output_file);

    end = clock();
    printf("Elapsed: %f\n", difftime(end, start) / CLOCKS_PER_SEC);

    return 0;
}
