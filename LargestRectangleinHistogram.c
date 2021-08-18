#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct stackt{
    int *arr;
    int front;
    int stackSize;
}stackT;

bool isStackEmpty(stackT *stack){
    return stack->front == -1;
}

bool isStackFull(stackT *stack){
    return stack->front == stack->stackSize;
}

stackT *createStack(int stackSize){
    stackT *stack = malloc(sizeof(stackT));
    if(!stack)  return NULL;
    stack->arr = malloc(sizeof(int)*stackSize);
    if(!stack->arr) return NULL;
    stack->front = -1;
    stack->stackSize = stackSize;
    return stack;
}

int stackPush(stackT *stack, int inputIdx){
    if(isStackFull(stack))  return -1;
    stack->arr[++stack->front] = inputIdx;
    return 1;
}

int stackPop(stackT *stack){
    if(isStackEmpty(stack))  return -1;
    return stack->arr[stack->front--];
}

int stackPeek(stackT *stack){
    if(isStackEmpty(stack))  return -1;
    return stack->arr[stack->front];
}

void freeStack(stackT *stack){
    free(stack->arr);
    free(stack);
}

int largestRectangleArea(int* heights, int heightsSize){
    int rowSize = heightsSize;
    int maxArea = 0;
    
    stackT *stack = createStack(heightsSize);
    if(!stack)  return false;
    
    for(int i=0; i<rowSize; i++){
        while((!isStackEmpty(stack)) && (heights[stackPeek(stack)] >= heights[i])){
            int currentHeight = heights[stackPop(stack)];
            int currentWidth = i-stackPeek(stack)-1;
            maxArea = MAX(maxArea, currentHeight * currentWidth);
        }
        stackPush(stack, i);
    }
    
    while(!isStackEmpty(stack)){
        int currentHeight = heights[stackPop(stack)];
        int currentWidth = rowSize-stackPeek(stack)-1;
        maxArea = MAX(maxArea, currentHeight * currentWidth);
    }
   return maxArea;    
}