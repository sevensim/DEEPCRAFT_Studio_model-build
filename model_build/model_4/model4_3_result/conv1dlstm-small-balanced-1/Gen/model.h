/*
* DEEPCRAFT Studio 5.5.3243+76c4d63272120e1aa149b27cfceadaf33de9e42c
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 07/24/2025 08:35:23 UTC. Any changes will be lost.
* 
* Model ID  3992dc41-3baf-40b7-a815-532b0fa9e94f
* 
* Memory    Size                      Efficiency
* Buffers   3840 bytes (RAM)          100 %
* State     128 bytes (RAM)           100 %
* Readonly  24024 bytes (Flash)       100 %
* 
* Backend              tensorflow
* Keras Version        2.15.0
* Backend Model Type   Sequential
* Backend Model Name   conv1dlstm-small-balanced-1
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
* Convolution 1D                 [30,16]         float      compute
*    filters = 16
*    kernel_size = 5
*    dilation_rate = 1
*    strides = 2
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[5,15,16]
* Batch Normalization            [30,16]         float      compute
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[16]
*    beta = float[16]
*    mean = float[16]
*    variance = float[16]
* Activation                     [30,16]         float      compute
*    activation = relu
*    trainable = True
* Convolution 1D                 [30,16]         float      compute
*    filters = 16
*    kernel_size = 5
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[5,16,16]
* Convolution 1D                 [30,16]         float      compute
*    filters = 16
*    kernel_size = 5
*    dilation_rate = 1
*    strides = 1
*    padding = same
*    activation = linear
*    use_bias = False
*    trainable = True
*    weight = float[5,16,16]
* Batch Normalization            [30,16]         float      compute
*    epsilon = 0.001
*    trainable = True
*    scale = True
*    center = True
*    axis = 2
*    gamma = float[16]
*    beta = float[16]
*    mean = float[16]
*    variance = float[16]
* Activation                     [30,16]         float      compute
*    activation = relu
*    trainable = True
* Max pooling 1D                 [15,16]         float      compute
*    pool_size = 2
*    strides = 2
*    padding = valid
*    trainable = True
* Dropout                        [15,16]         float      compute
*    rate = 0.1
*    trainable = True
* Long Short-Term Memory         [15,16]         float      compute
*    units = 16
*    activation = tanh
*    recurrent_activation = sigmoid
*    use_bias = True
*    return_sequences = True
*    return_state = False
*    stateful = False
*    go_backwards = False
*    trainable = True
*    kernel = float[16,64]
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
* (ACC) Accuracy 95.156 %
* (F1S) F1 Score 95.169 %
* 
* Name of class                                            (unlabelled)          Falling           normal          Sitting        Squatting           static
* (TP) True Positive or Correct Positive Prediction                   0              141              149               16              152               92
* (FN) False Negative or Incorrect Negative Prediction                0                2                7                1               13                5
* (FP) False Positive or Incorrect Positive Prediction                0                5                7                4                5                7
* (TN) True Negative or Correct Negative Prediction                 578              430              415              557              408              474
* (TPR) True Positive Rate or Sensitivity, Recall              100.00 %          98.60 %          95.51 %          94.12 %          92.12 %          94.85 %
* (TNR) True Negative Rate or Specificity, Selectivity         100.00 %          98.85 %          98.34 %          99.29 %          98.79 %          98.54 %
* (PPV) Positive Predictive Value or Precision                 100.00 %          96.58 %          95.51 %          80.00 %          96.82 %          92.93 %
* (NPV) Negative Predictive Value                              100.00 %          99.54 %          98.34 %          99.82 %          96.91 %          98.96 %
* (FNR) False Negative Rate or Miss Rate                       100.00 %           1.40 %           4.49 %           5.88 %           7.88 %           5.15 %
* (FPR) False Positive Rate or Fall-Out                          0.00 %           1.15 %           1.66 %           0.71 %           1.21 %           1.46 %
* (FDR) False Discovery Rate                                   100.00 %           3.42 %           4.49 %          20.00 %           3.18 %           7.07 %
* (FOR) False Omission Rate                                      0.00 %           0.46 %           1.66 %           0.18 %           3.09 %           1.04 %
* (F1S) F1 Score                                               100.00 %          97.58 %          95.51 %          86.49 %          94.41 %          93.88 %
*/


#define IMAI_TEST_AVG_ACC 0.9515570934256056 // Accuracy
#define IMAI_TEST_AVG_F1S 0.9516897177992342 // F1 Score

#define IMAI_TEST_STATS { \
 {name: "(unlabelled)", TP: 0, FN: 0, FP: 0, TN: 578, TPR: 1, TNR: 1, PPV: 1, NPV: 1, FNR: 1, FPR: 0, FDR: 1, FOR: 0, F1S: 1, }, \
 {name: "Falling", TP: 141, FN: 2, FP: 5, TN: 430, TPR: 0.9860139860139, TNR: 0.9885057471264, PPV: 0.9657534246575, NPV: 0.9953703703703, FNR: 0.0139860139860, FPR: 0.0114942528735, FDR: 0.0342465753424, FOR: 0.0046296296296, F1S: 0.9757785467128, }, \
 {name: "Squatting", TP: 152, FN: 13, FP: 5, TN: 408, TPR: 0.9212121212121, TNR: 0.9878934624697, PPV: 0.9681528662420, NPV: 0.9691211401425, FNR: 0.0787878787878, FPR: 0.0121065375302, FDR: 0.0318471337579, FOR: 0.0308788598574, F1S: 0.9440993788819, }, \
 {name: "normal", TP: 149, FN: 7, FP: 7, TN: 415, TPR: 0.9551282051282, TNR: 0.9834123222748, PPV: 0.9551282051282, NPV: 0.9834123222748, FNR: 0.0448717948717, FPR: 0.0165876777251, FDR: 0.0448717948717, FOR: 0.0165876777251, F1S: 0.9551282051282, }, \
 {name: "static", TP: 92, FN: 5, FP: 7, TN: 474, TPR: 0.9484536082474, TNR: 0.9854469854469, PPV: 0.9292929292929, NPV: 0.9895615866388, FNR: 0.0515463917525, FPR: 0.0145530145530, FDR: 0.0707070707070, FOR: 0.0104384133611, F1S: 0.9387755102040, }, \
 {name: "Sitting", TP: 16, FN: 1, FP: 4, TN: 557, TPR: 0.9411764705882, TNR: 0.9928698752228, PPV: 0.8, NPV: 0.9982078853046, FNR: 0.0588235294117, FPR: 0.0071301247771, FDR: 0.2, FOR: 0.0017921146953, F1S: 0.8648648648648, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_test_stats[] = IMAI_TEST_STATS;
#endif

/*
* Tensorflow Train Set
* 
* (ACC) Accuracy 98.551 %
* (F1S) F1 Score 98.554 %
* 
* Name of class                                            (unlabelled)          Falling           normal          Sitting        Squatting           static
* (TP) True Positive or Correct Positive Prediction                   0              663              712               78              755              444
* (FN) False Negative or Incorrect Negative Prediction                0                1               14                1               14                9
* (FP) False Positive or Incorrect Positive Prediction                0                8                6                7                6               12
* (TN) True Negative or Correct Negative Prediction                2691             2019             1959             2605             1916             2226
* (TPR) True Positive Rate or Sensitivity, Recall              100.00 %          99.85 %          98.07 %          98.73 %          98.18 %          98.01 %
* (TNR) True Negative Rate or Specificity, Selectivity         100.00 %          99.61 %          99.69 %          99.73 %          99.69 %          99.46 %
* (PPV) Positive Predictive Value or Precision                 100.00 %          98.81 %          99.16 %          91.76 %          99.21 %          97.37 %
* (NPV) Negative Predictive Value                              100.00 %          99.95 %          99.29 %          99.96 %          99.27 %          99.60 %
* (FNR) False Negative Rate or Miss Rate                       100.00 %           0.15 %           1.93 %           1.27 %           1.82 %           1.99 %
* (FPR) False Positive Rate or Fall-Out                          0.00 %           0.39 %           0.31 %           0.27 %           0.31 %           0.54 %
* (FDR) False Discovery Rate                                   100.00 %           1.19 %           0.84 %           8.24 %           0.79 %           2.63 %
* (FOR) False Omission Rate                                      0.00 %           0.05 %           0.71 %           0.04 %           0.73 %           0.40 %
* (F1S) F1 Score                                               100.00 %          99.33 %          98.61 %          95.12 %          98.69 %          97.69 %
*/


#define IMAI_TRAIN_AVG_ACC 0.9855072463768116 // Accuracy
#define IMAI_TRAIN_AVG_F1S 0.9855432557378782 // F1 Score

#define IMAI_TRAIN_STATS { \
 {name: "(unlabelled)", TP: 0, FN: 0, FP: 0, TN: 2691, TPR: 1, TNR: 1, PPV: 1, NPV: 1, FNR: 1, FPR: 0, FDR: 1, FOR: 0, F1S: 1, }, \
 {name: "Falling", TP: 663, FN: 1, FP: 8, TN: 2019, TPR: 0.9984939759036, TNR: 0.9960532807104, PPV: 0.9880774962742, NPV: 0.9995049504950, FNR: 0.0015060240963, FPR: 0.0039467192895, FDR: 0.0119225037257, FOR: 0.0004950495049, F1S: 0.9932584269662, }, \
 {name: "Squatting", TP: 755, FN: 14, FP: 6, TN: 1916, TPR: 0.9817945383615, TNR: 0.9968782518210, PPV: 0.9921156373193, NPV: 0.9927461139896, FNR: 0.0182054616384, FPR: 0.0031217481789, FDR: 0.0078843626806, FOR: 0.0072538860103, F1S: 0.9869281045751, }, \
 {name: "normal", TP: 712, FN: 14, FP: 6, TN: 1959, TPR: 0.9807162534435, TNR: 0.9969465648854, PPV: 0.9916434540389, NPV: 0.9929042067916, FNR: 0.0192837465564, FPR: 0.0030534351145, FDR: 0.0083565459610, FOR: 0.0070957932083, F1S: 0.9861495844875, }, \
 {name: "static", TP: 444, FN: 9, FP: 12, TN: 2226, TPR: 0.9801324503311, TNR: 0.9946380697050, PPV: 0.9736842105263, NPV: 0.9959731543624, FNR: 0.0198675496688, FPR: 0.0053619302949, FDR: 0.0263157894736, FOR: 0.0040268456375, F1S: 0.9768976897689, }, \
 {name: "Sitting", TP: 78, FN: 1, FP: 7, TN: 2605, TPR: 0.9873417721518, TNR: 0.9973200612557, PPV: 0.9176470588235, NPV: 0.9996162701458, FNR: 0.0126582278481, FPR: 0.0026799387442, FDR: 0.0823529411764, FOR: 0.0003837298541, F1S: 0.9512195121951, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_train_stats[] = IMAI_TRAIN_STATS;
#endif

/*
* Tensorflow Validation Set
* 
* (ACC) Accuracy 94.097 %
* (F1S) F1 Score 94.158 %
* 
* Name of class                                            (unlabelled)          Falling           normal          Sitting        Squatting           static
* (TP) True Positive or Correct Positive Prediction                   0              134              143               14              149               86
* (FN) False Negative or Incorrect Negative Prediction                0                4                8                2               11                8
* (FP) False Positive or Incorrect Positive Prediction                0                4                8                5                4               12
* (TN) True Negative or Correct Negative Prediction                 559              417              400              538              395              453
* (TPR) True Positive Rate or Sensitivity, Recall              100.00 %          97.10 %          94.70 %          87.50 %          93.13 %          91.49 %
* (TNR) True Negative Rate or Specificity, Selectivity         100.00 %          99.05 %          98.04 %          99.08 %          99.00 %          97.42 %
* (PPV) Positive Predictive Value or Precision                 100.00 %          97.10 %          94.70 %          73.68 %          97.39 %          87.76 %
* (NPV) Negative Predictive Value                              100.00 %          99.05 %          98.04 %          99.63 %          97.29 %          98.26 %
* (FNR) False Negative Rate or Miss Rate                       100.00 %           2.90 %           5.30 %          12.50 %           6.88 %           8.51 %
* (FPR) False Positive Rate or Fall-Out                          0.00 %           0.95 %           1.96 %           0.92 %           1.00 %           2.58 %
* (FDR) False Discovery Rate                                   100.00 %           2.90 %           5.30 %          26.32 %           2.61 %          12.24 %
* (FOR) False Omission Rate                                      0.00 %           0.95 %           1.96 %           0.37 %           2.71 %           1.74 %
* (F1S) F1 Score                                               100.00 %          97.10 %          94.70 %          80.00 %          95.21 %          89.58 %
*/


#define IMAI_VALIDATION_AVG_ACC 0.9409660107334525 // Accuracy
#define IMAI_VALIDATION_AVG_F1S 0.9415753161072279 // F1 Score

#define IMAI_VALIDATION_STATS { \
 {name: "(unlabelled)", TP: 0, FN: 0, FP: 0, TN: 559, TPR: 1, TNR: 1, PPV: 1, NPV: 1, FNR: 1, FPR: 0, FDR: 1, FOR: 0, F1S: 1, }, \
 {name: "Falling", TP: 134, FN: 4, FP: 4, TN: 417, TPR: 0.9710144927536, TNR: 0.9904988123515, PPV: 0.9710144927536, NPV: 0.9904988123515, FNR: 0.0289855072463, FPR: 0.0095011876484, FDR: 0.0289855072463, FOR: 0.0095011876484, F1S: 0.9710144927536, }, \
 {name: "Squatting", TP: 149, FN: 11, FP: 4, TN: 395, TPR: 0.93125, TNR: 0.9899749373433, PPV: 0.9738562091503, NPV: 0.9729064039408, FNR: 0.06875, FPR: 0.0100250626566, FDR: 0.0261437908496, FOR: 0.0270935960591, F1S: 0.9520766773162, }, \
 {name: "normal", TP: 143, FN: 8, FP: 8, TN: 400, TPR: 0.9470198675496, TNR: 0.9803921568627, PPV: 0.9470198675496, NPV: 0.9803921568627, FNR: 0.0529801324503, FPR: 0.0196078431372, FDR: 0.0529801324503, FOR: 0.0196078431372, F1S: 0.9470198675496, }, \
 {name: "static", TP: 86, FN: 8, FP: 12, TN: 453, TPR: 0.9148936170212, TNR: 0.9741935483870, PPV: 0.8775510204081, NPV: 0.9826464208242, FNR: 0.0851063829787, FPR: 0.0258064516129, FDR: 0.1224489795918, FOR: 0.0173535791757, F1S: 0.8958333333333, }, \
 {name: "Sitting", TP: 14, FN: 2, FP: 5, TN: 538, TPR: 0.875, TNR: 0.9907918968692, PPV: 0.7368421052631, NPV: 0.9962962962962, FNR: 0.125, FPR: 0.0092081031307, FDR: 0.2631578947368, FOR: 0.0037037037037, F1S: 0.8, }, \
}

#ifdef IMAI_STATS_ENABLED
static const IMAI_stats IMAI_validation_stats[] = IMAI_VALIDATION_STATS;
#endif

#define IMAI_API_FUNCTION

// All symbols in order
#define IMAI_SYMBOL_MAP {"unlabelled", "Falling", "Squatting", "normal", "static", "Sitting"}

// Model GUID (16 bytes)
#define IMAI_MODEL_ID {0x41, 0xdc, 0x92, 0x39, 0xaf, 0x3b, 0xb7, 0x40, 0xa8, 0x15, 0x53, 0x2b, 0x0f, 0xa9, 0xe9, 0x4f}

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

#define IMAI_KEY_MAX (71)



// Return codes
#define IMAI_RET_SUCCESS 0
#define IMAI_RET_NODATA -1
#define IMAI_RET_NOMEM -2

// Exported methods
void IMAI_compute(const float *restrict data_in, float *restrict data_out);
void IMAI_init(void);

#endif /* _IMAI_MODEL_H_ */
