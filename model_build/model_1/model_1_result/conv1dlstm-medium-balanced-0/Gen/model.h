/*
* DEEPCRAFT Studio 5.5.3243+76c4d63272120e1aa149b27cfceadaf33de9e42c
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 07/22/2025 07:56:11 UTC. Any changes will be lost.
* 
* Model ID  a40b48d2-6a91-4d4c-b5e9-f328f3bcd021
* 
* Memory    Size                      Efficiency
* Buffers   7200 bytes (RAM)          80 %
* State     128 bytes (RAM)           100 %
* Readonly  47256 bytes (Flash)       100 %
* 
* Backend              tensorflow
* Keras Version        2.15.0
* Backend Model Type   Sequential
* Backend Model Name   conv1dlstm-medium-balanced-0
* 
* Class Index | Symbol Label
* 0           | unlabelled
* 1           | Falling
* 2           | Squatting
* 3           | normal
* 4           | static
* 5           | Sitting
* 
* Layer                          Shape           Type       Function
* Input Layer                    [60,15]         float      compute
*    shape = [60,15]
* Convolution 1D                 [30,12]         float      compute
*    filters = 12
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 2
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,15,12]
* Batch Normalization            [30,12]         float      compute
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[12]
*    beta = float[12]
*    mean = float[12]
*    variance = float[12]
* Activation                     [30,12]         float      compute
*    activation = relu
*    trainable = True
* Convolution 1D                 [30,24]         float      compute
*    filters = 24
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,12,24]
* Convolution 1D                 [30,24]         float      compute
*    filters = 24
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,24,24]
* Batch Normalization            [30,24]         float      compute
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[24]
*    beta = float[24]
*    mean = float[24]
*    variance = float[24]
* Activation                     [30,24]         float      compute
*    activation = relu
*    trainable = True
* Max pooling 1D                 [15,24]         float      compute
*    pool_size = 2
*    strides = 2
*    padding = valid
*    trainable = True
* Convolution 1D                 [15,32]         float      compute
*    filters = 32
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,24,32]
* Convolution 1D                 [15,32]         float      compute
*    filters = 32
*    kernel_size = 3
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[3,32,32]
* Batch Normalization            [15,32]         float      compute
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[32]
*    beta = float[32]
*    mean = float[32]
*    variance = float[32]
* Activation                     [15,32]         float      compute
*    activation = relu
*    trainable = True
* Max pooling 1D                 [7,32]          float      compute
*    pool_size = 2
*    strides = 2
*    padding = valid
*    trainable = True
* Long Short-Term Memory         [7,16]          float      compute
*    units = 16
*    activation = tanh
*    recurrent_activation = sigmoid
*    use_bias = True
*    return_sequences = True
*    return_state = False
*    stateful = False
*    go_backwards = False
*    trainable = True
*    kernel = float[32,64]
*    recurrent_kernel = float[16,64]
*    bias = float[64]
* Global average pooling 1D      [16]            float      compute
*    trainable = True
* Dense                          [6]             float      compute
*    units = 6
*    use_bias = True
*    activation = linear
*    trainable = True
*    weight = float[16,6]
*    bias = float[6]
* Activation                     [6]             float      compute
*    activation = softmax
*    trainable = True
* 
* Exported functions:
* 
* void IMAI_compute(const float *restrict data_in, float *restrict data_out)
*    Description: Compute a forward pass
*    Parameter data_in is Input of size float[60,15].
*    Parameter data_out is Output of size float[6].
* 
* void IMAI_init(void)
*    Description: Initializes buffers to initial state. This function also works as a reset function.
* 
* 
* Disclaimer:
*   The generated code relies on the optimizations done by the C compiler.
*   For example many for-loops of length 1 must be removed by the optimizer.
*   This can only be done if the functions are inlined and simplified.
*   Check disassembly if unsure.
*   tl;dr Compile using gcc with -O3 or -Ofast
*/

#ifndef _IMAI_MODEL_H_
#define _IMAI_MODEL_H_
#ifdef _MSC_VER
#pragma once
#endif

#include <stdint.h>

typedef struct {    
    char *name;
    double TP; // True Positive or Correct Positive Prediction
    double FN; // False Negative or Incorrect Negative Prediction
    double FP; // False Positive or Incorrect Positive Prediction
    double TN; // True Negative or Correct Negative Prediction
    double TPR; // True Positive Rate or Sensitivity, Recall
    double TNR; // True Negative Rate or Specificity, Selectivity
    double PPV; // Positive Predictive Value or Precision
    double NPV; // Negative Predictive Value
    double FNR; // False Negative Rate or Miss Rate
    double FPR; // False Positive Rate or Fall-Out
    double FDR; // False Discovery Rate
    double FOR; // False Omission Rate
    double F1S; // F1 Score
} IMAI_stats;

/*
* Tensorflow Test Set
* 
* (ACC) Accuracy 89.404 %
* (F1S) F1 Score 89.354 %
* 
* Name of class                                            (unlabelled)          Falling           normal          Sitting        Squatting           static
* (TP) True Positive or Correct Positive Prediction                   0              137              151               12              147               93
* (FN) False Negative or Incorrect Negative Prediction                0               12               12                6               26                8
* (FP) False Positive or Incorrect Positive Prediction                0               10               18                4               18               14
* (TN) True Negative or Correct Negative Prediction                 604              445              423              582              413              489
* (TPR) True Positive Rate or Sensitivity, Recall              100.00 %          91.95 %          92.64 %          66.67 %          84.97 %          92.08 %
* (TNR) True Negative Rate or Specificity, Selectivity         100.00 %          97.80 %          95.92 %          99.32 %          95.82 %          97.22 %
* (PPV) Positive Predictive Value or Precision                 100.00 %          93.20 %          89.35 %          75.00 %          89.09 %          86.92 %
* (NPV) Negative Predictive Value                              100.00 %          97.37 %          97.24 %          98.98 %          94.08 %          98.39 %
* (FNR) False Negative Rate or Miss Rate                       100.00 %           8.05 %           7.36 %          33.33 %          15.03 %           7.92 %
* (FPR) False Positive Rate or Fall-Out                          0.00 %           2.20 %           4.08 %           0.68 %           4.18 %           2.78 %
* (FDR) False Discovery Rate                                   100.00 %           6.80 %          10.65 %          25.00 %          10.91 %          13.08 %
* (FOR) False Omission Rate                                      0.00 %           2.63 %           2.76 %           1.02 %           5.92 %           1.61 %
* (F1S) F1 Score                                               100.00 %          92.57 %          90.96 %          70.59 %          86.98 %          89.42 %
*/


#define IMAI_TEST_AVG_ACC 0.8940397350993378 // Accuracy
#define IMAI_TEST_AVG_F1S 0.893541788077984 // F1 Score

#define IMAI_TEST_STATS { \
 {name: "(unlabelled)", TP: 0, FN: 0, FP: 0, TN: 604, TPR: 1, TNR: 1, PPV: 1, NPV: 1, FNR: 1, FPR: 0, FDR: 1, FOR: 0, F1S: 1, }, \
 {name: "Falling", TP: 137, FN: 12, FP: 10, TN: 445, TPR: 0.9194630872483, TNR: 0.9780219780219, PPV: 0.9319727891156, NPV: 0.9737417943107, FNR: 0.0805369127516, FPR: 0.0219780219780, FDR: 0.0680272108843, FOR: 0.0262582056892, F1S: 0.9256756756756, }, \
 {name: "Squatting", TP: 147, FN: 26, FP: 18, TN: 413, TPR: 0.8497109826589, TNR: 0.9582366589327, PPV: 0.8909090909090, NPV: 0.9407744874715, FNR: 0.1502890173410, FPR: 0.0417633410672, FDR: 0.1090909090909, FOR: 0.0592255125284, F1S: 0.8698224852071, }, \
 {name: "normal", TP: 151, FN: 12, FP: 18, TN: 423, TPR: 0.9263803680981, TNR: 0.9591836734693, PPV: 0.8934911242603, NPV: 0.9724137931034, FNR: 0.0736196319018, FPR: 0.0408163265306, FDR: 0.1065088757396, FOR: 0.0275862068965, F1S: 0.9096385542168, }, \
 {name: "static", TP: 93, FN: 8, FP: 14, TN: 489, TPR: 0.9207920792079, TNR: 0.9721669980119, PPV: 0.8691588785046, NPV: 0.9839034205231, FNR: 0.0792079207920, FPR: 0.0278330019880, FDR: 0.1308411214953, FOR: 0.0160965794768, F1S: 0.8942307692307, }, \
 {name: "Sitting", TP: 12, FN: 6, FP: 4, TN: 582, TPR: 0.6666666666666, TNR: 0.9931740614334, PPV: 0.75, NPV: 0.9897959183673, FNR: 0.3333333333333, FPR: 0.0068259385665, FDR: 0.25, FOR: 0.0102040816326, F1S: 0.7058823529411, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_test_stats[] = IMAI_TEST_STATS;
#endif

/*
* Tensorflow Train Set
* 
* (ACC) Accuracy 98.422 %
* (F1S) F1 Score 98.421 %
* 
* Name of class                                            (unlabelled)          Falling           normal          Sitting        Squatting           static
* (TP) True Positive or Correct Positive Prediction                   0              649              715               77              735              443
* (FN) False Negative or Incorrect Negative Prediction                0                8                3                1               25                5
* (FP) False Positive or Incorrect Positive Prediction                0                5               10                3                9               15
* (TN) True Negative or Correct Negative Prediction                2661             1999             1933             2580             1892             2198
* (TPR) True Positive Rate or Sensitivity, Recall              100.00 %          98.78 %          99.58 %          98.72 %          96.71 %          98.88 %
* (TNR) True Negative Rate or Specificity, Selectivity         100.00 %          99.75 %          99.49 %          99.88 %          99.53 %          99.32 %
* (PPV) Positive Predictive Value or Precision                 100.00 %          99.24 %          98.62 %          96.25 %          98.79 %          96.72 %
* (NPV) Negative Predictive Value                              100.00 %          99.60 %          99.85 %          99.96 %          98.70 %          99.77 %
* (FNR) False Negative Rate or Miss Rate                       100.00 %           1.22 %           0.42 %           1.28 %           3.29 %           1.12 %
* (FPR) False Positive Rate or Fall-Out                          0.00 %           0.25 %           0.51 %           0.12 %           0.47 %           0.68 %
* (FDR) False Discovery Rate                                   100.00 %           0.76 %           1.38 %           3.75 %           1.21 %           3.28 %
* (FOR) False Omission Rate                                      0.00 %           0.40 %           0.15 %           0.04 %           1.30 %           0.23 %
* (F1S) F1 Score                                               100.00 %          99.01 %          99.10 %          97.47 %          97.74 %          97.79 %
*/


#define IMAI_TRAIN_AVG_ACC 0.9842164599774521 // Accuracy
#define IMAI_TRAIN_AVG_F1S 0.9842057489881473 // F1 Score

#define IMAI_TRAIN_STATS { \
 {name: "(unlabelled)", TP: 0, FN: 0, FP: 0, TN: 2661, TPR: 1, TNR: 1, PPV: 1, NPV: 1, FNR: 1, FPR: 0, FDR: 1, FOR: 0, F1S: 1, }, \
 {name: "Falling", TP: 649, FN: 8, FP: 5, TN: 1999, TPR: 0.9878234398782, TNR: 0.9975049900199, PPV: 0.9923547400611, NPV: 0.9960139511709, FNR: 0.0121765601217, FPR: 0.0024950099800, FDR: 0.0076452599388, FOR: 0.0039860488290, F1S: 0.9900839054157, }, \
 {name: "Squatting", TP: 735, FN: 25, FP: 9, TN: 1892, TPR: 0.9671052631578, TNR: 0.9952656496580, PPV: 0.9879032258064, NPV: 0.9869587897756, FNR: 0.0328947368421, FPR: 0.0047343503419, FDR: 0.0120967741935, FOR: 0.0130412102243, F1S: 0.9773936170212, }, \
 {name: "normal", TP: 715, FN: 3, FP: 10, TN: 1933, TPR: 0.9958217270194, TNR: 0.9948533196088, PPV: 0.9862068965517, NPV: 0.9984504132231, FNR: 0.0041782729805, FPR: 0.0051466803911, FDR: 0.0137931034482, FOR: 0.0015495867768, F1S: 0.9909909909909, }, \
 {name: "static", TP: 443, FN: 5, FP: 15, TN: 2198, TPR: 0.9888392857142, TNR: 0.9932218707636, PPV: 0.9672489082969, NPV: 0.9977303676804, FNR: 0.0111607142857, FPR: 0.0067781292363, FDR: 0.0327510917030, FOR: 0.0022696323195, F1S: 0.9779249448123, }, \
 {name: "Sitting", TP: 77, FN: 1, FP: 3, TN: 2580, TPR: 0.9871794871794, TNR: 0.9988385598141, PPV: 0.9625, NPV: 0.9996125532739, FNR: 0.0128205128205, FPR: 0.0011614401858, FDR: 0.0375, FOR: 0.0003874467260, F1S: 0.9746835443037, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_train_stats[] = IMAI_TRAIN_STATS;
#endif

/*
* Tensorflow Validation Set
* 
* (ACC) Accuracy 92.007 %
* (F1S) F1 Score 91.970 %
* 
* Name of class                                            (unlabelled)          Falling           normal          Sitting        Squatting           static
* (TP) True Positive or Correct Positive Prediction                   0              135              141               13              141               88
* (FN) False Negative or Incorrect Negative Prediction                0                4               11                3               20                7
* (FP) False Positive or Incorrect Positive Prediction                0                9               16                1               11                8
* (TN) True Negative or Correct Negative Prediction                 563              415              395              546              391              460
* (TPR) True Positive Rate or Sensitivity, Recall              100.00 %          97.12 %          92.76 %          81.25 %          87.58 %          92.63 %
* (TNR) True Negative Rate or Specificity, Selectivity         100.00 %          97.88 %          96.11 %          99.82 %          97.26 %          98.29 %
* (PPV) Positive Predictive Value or Precision                 100.00 %          93.75 %          89.81 %          92.86 %          92.76 %          91.67 %
* (NPV) Negative Predictive Value                              100.00 %          99.05 %          97.29 %          99.45 %          95.13 %          98.50 %
* (FNR) False Negative Rate or Miss Rate                       100.00 %           2.88 %           7.24 %          18.75 %          12.42 %           7.37 %
* (FPR) False Positive Rate or Fall-Out                          0.00 %           2.12 %           3.89 %           0.18 %           2.74 %           1.71 %
* (FDR) False Discovery Rate                                   100.00 %           6.25 %          10.19 %           7.14 %           7.24 %           8.33 %
* (FOR) False Omission Rate                                      0.00 %           0.95 %           2.71 %           0.55 %           4.87 %           1.50 %
* (F1S) F1 Score                                               100.00 %          95.41 %          91.26 %          86.67 %          90.10 %          92.15 %
*/


#define IMAI_VALIDATION_AVG_ACC 0.9200710479573713 // Accuracy
#define IMAI_VALIDATION_AVG_F1S 0.919704323930295 // F1 Score

#define IMAI_VALIDATION_STATS { \
 {name: "(unlabelled)", TP: 0, FN: 0, FP: 0, TN: 563, TPR: 1, TNR: 1, PPV: 1, NPV: 1, FNR: 1, FPR: 0, FDR: 1, FOR: 0, F1S: 1, }, \
 {name: "Falling", TP: 135, FN: 4, FP: 9, TN: 415, TPR: 0.9712230215827, TNR: 0.9787735849056, PPV: 0.9375, NPV: 0.9904534606205, FNR: 0.0287769784172, FPR: 0.0212264150943, FDR: 0.0625, FOR: 0.0095465393794, F1S: 0.9540636042402, }, \
 {name: "Squatting", TP: 141, FN: 20, FP: 11, TN: 391, TPR: 0.8757763975155, TNR: 0.9726368159203, PPV: 0.9276315789473, NPV: 0.9513381995133, FNR: 0.1242236024844, FPR: 0.0273631840796, FDR: 0.0723684210526, FOR: 0.0486618004866, F1S: 0.9009584664536, }, \
 {name: "normal", TP: 141, FN: 11, FP: 16, TN: 395, TPR: 0.9276315789473, TNR: 0.9610705596107, PPV: 0.8980891719745, NPV: 0.9729064039408, FNR: 0.0723684210526, FPR: 0.0389294403892, FDR: 0.1019108280254, FOR: 0.0270935960591, F1S: 0.9126213592233, }, \
 {name: "static", TP: 88, FN: 7, FP: 8, TN: 460, TPR: 0.9263157894736, TNR: 0.9829059829059, PPV: 0.9166666666666, NPV: 0.9850107066381, FNR: 0.0736842105263, FPR: 0.0170940170940, FDR: 0.0833333333333, FOR: 0.0149892933618, F1S: 0.9214659685863, }, \
 {name: "Sitting", TP: 13, FN: 3, FP: 1, TN: 546, TPR: 0.8125, TNR: 0.9981718464351, PPV: 0.9285714285714, NPV: 0.9945355191256, FNR: 0.1875, FPR: 0.0018281535648, FDR: 0.0714285714285, FOR: 0.0054644808743, F1S: 0.8666666666666, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_validation_stats[] = IMAI_VALIDATION_STATS;
#endif

#define IMAI_API_FUNCTION

// All symbols in order
#define IMAI_SYMBOL_MAP {"unlabelled", "Falling", "Squatting", "normal", "static", "Sitting"}

// Model GUID (16 bytes)
#define IMAI_MODEL_ID {0xd2, 0x48, 0x0b, 0xa4, 0x91, 0x6a, 0x4c, 0x4d, 0xb5, 0xe9, 0xf3, 0x28, 0xf3, 0xbc, 0xd0, 0x21}

// First nibble is bit encoding, second nibble is number of bytes
#define IMAGINET_TYPES_NONE	(0x0)
#define IMAGINET_TYPES_FLOAT32	(0x14)
#define IMAGINET_TYPES_FLOAT64	(0x18)
#define IMAGINET_TYPES_INT8	(0x21)
#define IMAGINET_TYPES_INT16	(0x22)
#define IMAGINET_TYPES_INT32	(0x24)
#define IMAGINET_TYPES_INT64	(0x28)
#define IMAGINET_TYPES_QDYN8	(0x31)
#define IMAGINET_TYPES_QDYN16	(0x32)
#define IMAGINET_TYPES_QDYN32	(0x34)

// data_in [60,15] (3600 bytes)
#define IMAI_DATA_IN_COUNT (900)
#define IMAI_DATA_IN_TYPE float
#define IMAI_DATA_IN_TYPE_ID IMAGINET_TYPES_FLOAT32
#define IMAI_DATA_IN_SCALE (1)
#define IMAI_DATA_IN_OFFSET (0)
#define IMAI_DATA_IN_IS_QUANTIZED (0)

// data_out [6] (24 bytes)
#define IMAI_DATA_OUT_COUNT (6)
#define IMAI_DATA_OUT_TYPE float
#define IMAI_DATA_OUT_TYPE_ID IMAGINET_TYPES_FLOAT32
#define IMAI_DATA_OUT_SCALE (1)
#define IMAI_DATA_OUT_OFFSET (0)
#define IMAI_DATA_OUT_IS_QUANTIZED (0)

#define IMAI_KEY_MAX (82)



// Return codes
#define IMAI_RET_SUCCESS 0
#define IMAI_RET_NODATA -1
#define IMAI_RET_NOMEM -2

// Exported methods
void IMAI_compute(const float *restrict data_in, float *restrict data_out);
void IMAI_init(void);

#endif /* _IMAI_MODEL_H_ */
