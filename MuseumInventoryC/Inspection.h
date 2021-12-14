#include "Question.h"
#include "LinkedListQueue.h"
#include "BinaryQuestion.h"
#include "NoteQuestion.h"

#pragma once
class Inspection
{
public:
	LinkedListQueue questions;

	Inspection()
	{
		questions = LinkedListQueue();

		BinaryQuestion* question1 = new BinaryQuestion("Functioning", "Is the item functional?");
		NoteQuestion* question2 = new NoteQuestion("Functioning Complications", "Are there any complications with the function?");
		BinaryQuestion* question3 = new BinaryQuestion("Showcases", "Is this item currently showcased in the museum?");

		questions.enqueue(question1);
		questions.enqueue(question2);
		questions.enqueue(question3);
	}
};

