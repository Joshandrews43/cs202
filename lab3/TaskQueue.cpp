
#include "TaskQueue.h"

TaskQueue::
TaskQueue()
{
    // TODO: Your code here.
    smutex_init(&this->lock);
    scond_init(&this->fill);
}

TaskQueue::
~TaskQueue()
{
    // TODO: Your code here.
    smutex_destroy(&this->lock);
    scond_destroy(&this->fill);
}

/*
 * ------------------------------------------------------------------
 * size --
 *
 *      Return the current size of the queue.
 *
 * Results:
 *      The size of the queue.
 *
 * ------------------------------------------------------------------
 */
int TaskQueue::
size()
{
    // TODO: Your code here.
    smutex_lock(&this->lock);

    int size = this->task_queue.size();

    smutex_unlock(&this->lock);

    return size; // Keep compiler happy until routine done.
}

/*
 * ------------------------------------------------------------------
 * empty --
 *
 *      Return whether or not the queue is empty.
 *
 * Results:
 *      The true if the queue is empty and false otherwise.
 *
 * ------------------------------------------------------------------
 */
bool TaskQueue::
empty()
{
    // TODO: Your code here.
    smutex_lock(&this->lock);

    bool is_empty = this->task_queue.empty();

    smutex_unlock(&this->lock);

    return is_empty; // Keep compiler happy until routine done.
}

/*
 * ------------------------------------------------------------------
 * enqueue --
 *
 *      Insert the task at the back of the queue.
 *
 * Results:
 *      None.
 *
 * ------------------------------------------------------------------
 */
void TaskQueue::
enqueue(Task task)
{
    // TODO: Your code here.
    smutex_lock(&this->lock);

    this->task_queue.push(task);

    scond_signal(&this->fill, &this->lock);
    smutex_unlock(&this->lock);
}

/*
 * ------------------------------------------------------------------
 * dequeue --
 *
 *      Remove the Task at the front of the queue and return it.
 *      If the queue is empty, block until a Task is inserted.
 *
 * Results:
 *      The Task at the front of the queue.
 *
 * ------------------------------------------------------------------
 */
Task TaskQueue::
dequeue()
{
    // TODO: Your code here.
    smutex_lock(&this->lock);

    while (this->task_queue.empty()) {
        scond_wait(&this->fill, &this->lock);
    }

    Task task = this->task_queue.front();
    this->task_queue.pop();

    smutex_unlock(&this->lock);

    return task; // Keep compiler happy until routine done.
}

